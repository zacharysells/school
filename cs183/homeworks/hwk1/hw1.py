#!/usr/bin/python
import sys

argv_it = iter(sys.argv)
next(argv_it)
for arg in argv_it:
    #print contents of files
    with open(arg) as file:
        sys.stdout.write( file.read() )
