#!/usr/bin/python

import socket
from check import ip_checksum
import sys
from time import sleep

HOST = '127.0.0.1'
PORT = 3217
expected_seq = 0

def makeack(seq, msg):
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
        if expected_seq == pckt_seq:
            print "Message from client: " + pckt_msg
            if pckt_msg == "timeout":
                sleep(5)
            print "Sending ACK"
            expected_seq = expected_seq + 1
            ack = makeack(expected_seq, "ACK..." + pckt_msg)
            s.sendto(ack, addr)

    else:
        print "Rejected Packet"
        # Bad packet. Send ACK for last received packet
        ack = makeack(expected_seq, "ACK..." + pckt_msg)
        s.sendto(ack, addr)

s.close()
