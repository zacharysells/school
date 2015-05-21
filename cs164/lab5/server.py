#!/usr/bin/python

import socket
from check import ip_checksum
import sys
from time import sleep

HOST = '127.0.0.1'
PORT = 3217
seq_num = "0"

def makeack(s, seq, msg):
    ack = seq + ip_checksum(msg) + msg
    return ack

def chkpckt(pckt):
    pckt_seq = pckt[0:1]
    pckt_chksum = pckt[1:3]
    pckt_msg = pckt[3:]
    if pckt_chksum == ip_checksum(pckt_msg):
        return (True, pckt_seq, pckt_msg)
    else:
        return (False, pckt_seq, pckt_msg)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print 'Socket created'

try:
    s.bind((HOST, PORT))
except socket.error, msg:
    print 'Bind failed. Error code : ' + str(msg[0]) + ' Message: ' + msg[1]
    sys.exit()

print 'Socket bind complete'

while 1:
    pckt, addr = s.recvfrom(1024)
    data = chkpckt(pckt)
    if data[0]:
        # Good packet. Send ACK
        pckt_seq = data[1]
        pckt_msg = data[2]
        if seq_num == pckt_seq:
            print "Message from client: " + pckt_msg
            if pckt_msg == "timeout":
                sleep(5)
            print "Sending ACK"
            ack = makeack(s, pckt_seq, "ACK..." + pckt_msg)
            s.sendto(ack, addr)

            # Flip sequence number
            if seq_num == "0":
                seq_num = "1"
            elif seq_num == "1":
                seq_num = "0"

    else:
        print "Bad checksum"
        # Bad packet. Do nothing

s.close()
