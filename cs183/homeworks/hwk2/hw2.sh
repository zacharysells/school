#!/bin/bash
exit #So this script is not actually executed as that may cause problems...

# dd can be used to copy data across files, partitions, and volumes
# this particular example clones the hard disk at /dev/ad0 to /dev/ad1
# 'noerror' specifies to continue if an error occurs.
dd if=/dev/ad0 of=/dev/ad1 bs=1M conv=noerror

# find can be used to find specific types of files in certain directory
# this particular example searches the /var/log directory for any files
# ending in '.log' that belong to the user zsell001
find /var/log -name *.log -user zsell001 

# file is used to classify files.
# this particular example clasifies this script, 'hw1.sh' as a
# Bourn-again shell script text executable
file hw1.sh

# fuser is used to find which processes are using a file
# this particular example displays all processes currently accessing
# the filesystem on which the file argument resides
fuser -v -m /var/log/yum.log

# grep searches files for matches in a pattern(regex). If a match is found, 
# grep will by default print the line containing the match.
# this particular example searches all files in the ~/code/src/ directory
# for any text with the expression "exit(1)"
grep -r 'exit(1)' ~/code/src/

# the host command does a DNS lookup of a given domain name. It returns 
# the IP address and other useful information of the given domain name.
# This particular example looks up the ip information of google.com
host google.com

# ldd prints the shared libraries that are dependencies of the input program
# this particular example prints the shared libraries required by the 'ls' 
# command
ldd /bin/ls

# lsof stands for 'list of open files'. It's used to list the files that are
# currently open by various processes. This particular example prints the
# process that currently has the /var/log/maillog file open
lsof /var/log/maillog

# mount is used to mount a filesystem on a directory. This particular mounts
# the network drive on IP address 136.99.9.10 on the /mnt/network directory
mount -t nfs //136.99.9.10 /mnt/network

# ps lists all processes that are currently running. This particular example
# prints detailed information about all the processes owned by the user 
# zsell001
ps -f -u zsell001

# pkill sends process signals to specified processes. This particular example 
# sends the SIGTERM signal(default) to the process with the name mysqld 
pkill mysqld

# netstate displays various network related information. This particular example
# lists all the active listening sockets currently running
netstat -l

# renice alters the scheduling priority of a running process. This particular
# example alters the changes the priority of the process with ID 1234 to 5.
renice -n 5 -p 1234

# rsync is used to copy and synchronize files remotely and locally. This 
# particular example copies files from a remote server to local machine using
# ssh
rsync -aze ssh zsell001@bell.cs.ucr.edu/:home/zsell001/docs/cs183/hw2.txt ~/

# time runs a specified program and prints timing statistics about the program
# that was run. This particular example times how long it takes to run a grep
# command.
time grep -r "ERROR 32221" /var/logs/

# ssh is a program for logging into a remote machine to execute commands. This 
# particular example connects to the ucr bell server with the login zsell001
ssh zsell001@bell.cs.ucr.edu

# stat prints information about the specified file such as size, user ID, 
# timestamps, inode, and more. This particular example prints information
# about the .bash_profile file. 
stat /home/zsell001/.bash_profile

# strace runs a specified command until it exits. It records system calls 
# that are called by the process and also the signals that are received by
# that process. This particular example prints the system calls and return
# values used by the ls command
strace ls

# uname prints information about the current system. This particular example
# prints the currents system's processor type.
uname -p

# wget downloads a specified webpage to a local directory. This particular
# example downloads a copy of the entire website stucture of techspot.com,
# recursively. It also sends the output to a logfile.
wget -r techspot.com -o logfile
