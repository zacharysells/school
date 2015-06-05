#!/usr/bin/python

import socket
import select
import sys
import datetime


HOST = '127.0.0.1'
PORT = 3217

class Message:
    def __init__(self, content, hashtags, op):
        self.content = content
        self.hashtags = hashtags
        self.op = op
        self.timestamp = datetime.datetime.now()

    def __str__(self):
        return self.op.username + ":" + self.content


class User:
    def __init__(self, uname, pword):
        self.username = uname
        self.password = pword
        self.addr = None
        self.subscribers = set()
        self.subscriptions = set()
        self.posted_msgs = []
        self.unread_msgs = []

    def __hash__(self):
        return hash(id(self))
    def __eq__(self, other):
        return self.username == other.username and self.password == other.password
    def __str__(self):
        return self.username
    def __repr__(self):
        return self.username

users = [User('zach', 'pword'),
         User('jai', 'pword'),
         User('admin', 'admin')]

def is_user(uname):
    global users

    for user in users:
        if user.username == uname:
            return True
    return False

def is_logged_in(user):
    return user.addr != None

def get_user_at_addr(addr):
    global users

    for user in users:
        if user.addr == addr:
            return user
    return None

def get_user_with_username(uname):
    global users

    for user in users:
        if user.username == uname:
            return user
    return None

def authenticate(uname, pword, addr):
    global users

    for user in users:
        if User(uname, pword) == user:
            user.addr = addr
            return True

    return False

def logout(uname, pword):
    global users

    for user in users:
        if User(uname, pword) == user:
            user.addr = None
            return

def get_stored_message_count():
    global users

    msg_count = 0
    for user in users:
        msg_count = msg_count + len(user.unread_msgs)

    return msg_count

def print_logged_in_users():
    global users

    for user in users:
        if user.addr is not None:
            print user.username + " is logged in at " + str(user.addr[0]) + ":" + str(user.addr[1])

def get_all_messages():
    global users

    messages = []
    for user in users:
        messages.extend(user.posted_msgs)

    return messages


def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print 'Socket created'

    try:
        s.bind((HOST, PORT))
    except socket.error, msg:
        print 'Bind failed. Error code : ' + str(msg[0]) + ' Message: ' + msg[1]
        sys.exit()

    print 'Socket bind complete. Waiting for connections'
    inputs = [s, sys.stdin]
    outputs = []
    while 1:
        readable, writeable, exceptional = select.select(inputs, outputs, inputs)

        for r in readable:

            if r is sys.stdin:
                cmd = raw_input()
                if cmd == 'messagecount':
                    print "Total Messages sent: ", len(get_all_messages())

                elif cmd == 'usercount':
                    print_logged_in_users()

                elif cmd == 'storedcount':
                    print str(get_stored_message_count())


            else:
                msg, addr = s.recvfrom(1024)
                msg_type = msg.split(':')[0]


                if msg_type == "auth":
                    uname = msg.split(':')[1]
                    pword = msg.split(':')[2]
                    print "authenticating user " + uname
                    if authenticate(uname, pword, addr):
                        print uname + " is logged in"
                        s.sendto("auth_ok", addr)
                    else:
                        print "authentication failed"
                        s.sendto("auth_failed", addr)

                elif msg_type == "logout":
                    uname = msg.split(':')[1]
                    pword = msg.split(':')[2]
                    print "logging out user " + uname
                    logout(uname, pword)

                elif msg_type == "all_logged_in":
                    print_logged_in_users()

                elif msg_type == "get_sub":
                    user = get_user_at_addr(addr)
                    s.sendto(":".join(str(uname) for uname in user.subscriptions), addr)

                elif msg_type == "drop_sub":
                    user = get_user_at_addr(addr)
                    drop_sub = msg.split(':')[1]
                    drop_user = get_user_with_username(drop_sub)
                    print user.username + " is unsubscribing from " + drop_sub
                    user.subscriptions.remove(drop_user)
                    drop_user.subscribers.remove(user)

                elif msg_type == "add_sub":
                    sub_name = msg.split(':')[1]
                    user = get_user_at_addr(addr)
                    if is_user(sub_name):
                        print user.username + " is subscribing to " + sub_name
                        sub_user = get_user_with_username(sub_name)
                        sub_user.subscribers.add(user)
                        user.subscriptions.add(sub_user)

                        # Tell user he is now subscribed to sub_user
                        s.sendto("add_sub_ok", addr)

                        # Tell sub_user that user is subscribed to him only if sub_user is logged in
                        if is_logged_in(sub_user):
                            s.sendto("sub_from:" + user.username, sub_user.addr)

                    else:
                        print sub_name + " is not a user"
                        s.sendto("add_sub_failed", addr)

                elif msg_type == "post_msg":
                    user = get_user_at_addr(addr)
                    content = msg.split(':')[1]
                    hashtags = msg.split(':')[2].split('#')
                    post = Message(content, hashtags, user)

                    user.posted_msgs.append(post)

                    # Notify subscribers of new post
                    for sub in user.subscribers:

                        # If subscriber is logged in, send them a message
                        if is_logged_in(sub):
                            msg = "new_msg:" + post.op.username + ":" + post.content
                            s.sendto(msg, sub.addr)

                        # If subscriber is not logged in, leave the notification in their unread list
                        else:
                            sub.unread_msgs.append(post)

                elif msg_type == "unread_msg":
                    user = get_user_at_addr(addr)
                    msgs = ":".join(str(msg) for msg in user.unread_msgs)
                    s.sendto(msgs, user.addr)

                elif msg_type == "clear_unread_msg":
                    user = get_user_at_addr(addr)
                    sub_name = msg.split(':')[1]
                    if sub_name == 'all':
                        print "clearing all", user.username, "'s messages"
                        del user.unread_msgs[:]

                    else:
                        print "clearing ", user.username, "'s messages from ", sub_name
                        user.unread_msgs[:] = [msg for msg in user.unread_msgs if msg.op.username != sub_name]

                elif msg_type == "hashtag_search":
                    hashtag = msg.split(':')[1]
                    all_messages = get_all_messages()
                    #print ":".join([msg.op.username + ":" + msg.content for msg in all_messages if hashtag in msg.hashtags])
                    s.sendto(":".join([msg.op.username + ":" + msg.content for msg in all_messages if hashtag in msg.hashtags]), addr)




if __name__ == "__main__":
    main()
