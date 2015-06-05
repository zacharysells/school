#!/usr/bin/python

import socket
import select
import sys
import atexit

uname = None
pword = None


def login(s, serv_addr):
    global uname, pword
    print "Please log in"
    uname = raw_input('username: ')
    pword = raw_input('password: ')

    msg = "auth:" + uname + ":" + pword
    s.sendto(msg, serv_addr)

    recv, addr = s.recvfrom(1024)
    if recv.split(':')[0] == "auth_ok":
        return True
    else:
        return False

def logout(s, serv_addr):
    global uname, pword
    msg = "logout:" + uname + ":" + pword
    s.sendto(msg, serv_addr)

def get_subscriptions(s, serv_addr):
    msg = "get_sub:"
    s.sendto(msg, serv_addr)
    recv, addr = s.recvfrom(1024)

    return recv.split(':')

def edit_subscriptions(s, serv_addr):
    print "********************************"
    print "1.) Add a subscription"
    print "2.) Drop a suscription"
    print "3.) Go back"
    cmd = raw_input('What do you want to do? ')

    if cmd == '1':
        print "********************************"
        uname = raw_input("Enter username: ")
        msg = "add_sub:" + uname
        s.sendto(msg, serv_addr)
        recv, addr = s.recvfrom(1024)

        if recv == "add_sub_ok":
            print "You are now subscribed to " + uname
        else:
            print uname + " is not a user"

    elif cmd == '2':
        print "********************************"
        print "Subscriptions:"
        subs = get_subscriptions(s, serv_addr)
        i = 1
        for sub in subs:
            if sub == '':
                continue
            print str(i) + ".) " + sub
            i = i + 1
        print str(i) + ".) Go Back"
        cmd = raw_input('Which subscription do you want to drop? ')
        # User is requesting to go back
        if cmd == str(i):
            return

        drop_sub = subs[int(cmd) - 1]
        s.sendto("drop_sub:" + drop_sub, serv_addr)

    elif cmd == '3':
        return
    else:
        print "Not a valid option"
        edit_subscriptions(s, serv_addr)

def post_message(s, serv_addr):
    content = raw_input("Message contents(140 chars): ")
    if len(content) <= 140:
        hashtags = '#' + raw_input("Hashtags: #")
        s.sendto("post_msg:" + content + ":" + hashtags, serv_addr)

    else:
        print "Message content must be 140 characters or less"
        post_message(s, serv_addr)

def get_unread_messages(s, serv_addr):
    msg = "unread_msg:"
    s.sendto(msg, serv_addr)
    recv, addr = s.recvfrom(1024)
    # TODO decode list of unread messages

    message_list = recv.split(':')
    messages = []
    for i in range(0, len(message_list)-1, 2):
        messages.append((message_list[i], message_list[i+1]))

    return messages

def see_offline_messages(s, serv_addr, unread_msg):
    print "********************************"
    print "1.) See all messages"
    print "2.) See messages from specific subscriber"
    print "3.) Go back"
    cmd = raw_input('What do you want to do? ')

    if cmd == '1':
        print "********************************"
        for msg in unread_msg:
            print "From:", msg[0]
            print "\t", msg[1]
        s.sendto('clear_unread_msg:all', serv_addr)

    elif cmd == '2':
        print "********************************"
        uname = raw_input("See messages from which subscriber? ")
        for msg in unread_msg:
            if msg[0] == uname:
                print "From:", msg[0]
                print "\t", msg[1]
        s.sendto('clear_unread_msg:' + uname, serv_addr)

    elif cmd == '3':
        return
    else:
        print "Not a valid option"
        see_offline_messages(s, serv_addr, unread_msg)

def hashtag_search(s, serv_addr):
    print "********************************"
    hashtag = raw_input('Search for what hashtag? #')
    s.sendto("hashtag_search:" + hashtag, serv_addr)
    recv, addr = s.recvfrom(1024)
    message_list = recv.split(':')
    for i in range(0, len(message_list)-1, 2):
        print "From: ", message_list[i]
        print "\t", message_list[i+1]



def print_menu():
    print "********************************"
    print "1.) Do nothing"
    print "2.) See whos logged in"
    print "3.) Edit subscriptions"
    print "4.) Post message"
    print "5.) See offline messages"
    print "6.) Hashtag search"
    print "9.) Logout"
    print 'What do you want to do? '

def main():
    host = '127.0.0.1'
    port = 3217
    serv_addr = (host, port)

    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    except socket.error:
        print 'Failed to create socket'
        sys.exit()
    print 'Socket Created'

    while not login(s, serv_addr):
        print "Unsuccessful login. Try again"

    unread_msg = get_unread_messages(s, serv_addr)
    print "Welcome %s. You have %d unread messages" % (uname, len(unread_msg))
    print_menu()
    atexit.register(logout, s, serv_addr)


    inputs = [s, sys.stdin]
    outputs = []
    show_menu = True
    while 1:
        readable, writeable, exceptional = select.select(inputs, outputs, inputs)

        for r in readable:

            if r is sys.stdin:
                cmd = raw_input()
                if cmd == '1':
                    pass

                elif cmd == '2':
                    msg = "all_logged_in"
                    s.sendto(msg, serv_addr)

                elif cmd == '3':
                    edit_subscriptions(s, serv_addr)

                elif cmd == '4':
                    post_message(s, serv_addr)

                elif cmd == '5':
                    see_offline_messages(s, serv_addr, unread_msg)

                elif cmd == '6':
                    hashtag_search(s, serv_addr)

                elif cmd == '9':
                    exit()

                else:
                    print "Not a valid option"

                print_menu()

            else:
                msg, addr = s.recvfrom(1024)
                msg_type = msg.split(':')[0]

                print "**************************"
                print "New Message from Server"

                if msg_type == 'sub_from':
                    sub_name = msg.split(':')[1]
                    print "\tSubscription from " + sub_name

                elif msg_type == 'new_msg':
                    op = msg.split(':')[1]
                    content = msg.split(':')[2]
                    print "\tNew post from " + op + ": " + content



if __name__ == "__main__":
    main()
