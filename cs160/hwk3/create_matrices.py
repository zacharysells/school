#!/usr/bin/python

import sys
import random

n = 100
FILE = open("matrices", 'w')

FILE.write(str(n-1) + '\n')

for i in range(0,n):
    for e in range(0, n):
        FILE.write(str(random.randint(1, 9)) + " ")

    FILE.write("\n")

FILE.write("---\n")

for i in range(0,n):
    for e in range(0, n):
        FILE.write(str(random.randint(1, 9)) + " ")

    FILE.write("\n")
