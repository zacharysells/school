#!/usr/bin/python

import socket
import sys
from thread import *

HOST = '127.0.0.1'
PORT = 3217

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Socket created'

try:
    s.bind((HOST, PORT))
except socket.error, msg:
    print 'Bind failed. Error code : ' + str(msg[0]) + ' Message: ' + msg[1]
    sys.exit()

print 'Socket bind complete'

# Backlog a max of 10 connections
s.listen(10)
print 'Socket now listening'

connections = []
def clientthread(conn, addr):
    print 'Connected with ' + addr[0] + ':' + str(addr[1])
    conn.send('Welcome to the server. Type something and hit enter\n')
    while 1:

        data = conn.recv(1024)
        reply = 'OK...' + data
        if not data:
            break
        elif data[0:12] == 'Send to all:':
            print 'Forward to all clients: ' + data[12:],
            for connection in connections:
                if conn is connection:
                    continue
                connection.send('BROADCAST MESSAGE FROM: ' + addr[0] + ':' + str(addr[1]) + ' : ' + data[12:])

        else:
            conn.sendall(reply)

    print 'Disconnected with ' + addr[0] + ':' + str(addr[1])
    conn.close()

while 1:
    conn, addr = s.accept()
    connections.append(conn)
    start_new_thread(clientthread, (conn,addr))
s.close()
