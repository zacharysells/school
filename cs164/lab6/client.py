#!/usr/bin/python

import socket
import select
import sys
from check import ip_checksum

bad_checksum = True
window_size = 4

seq_base = 0
seq_max = window_size - 1

host = '127.0.0.1'
port = 3217;
serv_addr = (host, port)

def makebadpckt(msg):
    global seq_num
    pckt = seq_num + "HI" + msg

    return pckt

def makepckt(msg):
    global seq_num
    pckt = seq_num + ip_checksum(msg) + msg

    return pckt

def chkpckt(pckt):
    pckt_seq = pckt[0:1]
    pckt_chksum = pckt[1:3]
    pckt_msg = pckt[3:]
    if pckt_chksum == ip_checksum(pckt_msg):
        return (True, pckt_seq, pckt_msg)
    else:
        return (False, pckt_seq, pckt_msg)

def recvack(s, pckt, msg):
    while(1):
        inputs = [s, sys.stdin]
        outputs = []
        timeout = 4
        readable, writeable, exceptional = select.select(inputs, outputs, inputs, timeout)

        if readable:
            pckt, addr = s.recvfrom(1024)
            data = chkpckt(pckt)
            if data[0]:
                # Good packet. Check seq number
                global seq_num
                if seq_num == data[1]:
                    # Good ACK. Alternate seq bit
                    print "ACK Recieved"
                    if seq_num == "0":
                        seq_num = "1"
                    elif seq_num == "1":
                        seq_num = "0"
                    break
        else:
            print "Resending packet"
            global serv_addr
            pckt = makepckt(msg)
            sendpckt(s, serv_addr, pckt)

def sendpckt(s, serv_addr, pckt):
    #badpckt = makebadpckt(s, msg)
    s.sendto(pckt, serv_addr)

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
except socket.error:
    print 'Failed to create socket'
    sys.exit()
print 'Socket Created'

while(1):
    msg = raw_input('Enter message : ')
    if msg == "corrupt":
        pckt = makebadpckt(msg)
    else:
        pckt = makepckt(msg)
    sendpckt(s, serv_addr, pckt)
    recvack(s, pckt, msg)

    # if bad_checksum:
    #     s.sendto(badpckt, addr)
    #     bad_checksum = False
    # else:
    #     s.sendto(pckt, addr)
