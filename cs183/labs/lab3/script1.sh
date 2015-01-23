#!/bin/bash

echo "1.) Finding all files in /bin, /sbin, /usr/bin, /user/sbin that are setuid and owned by root..."
read -p "Press any key to continue. "

find /bin /sbin /usr/bin /usr/sbin -user root -type f -perm -4000 

echo "2.) Finding all files in /var that have been modified within the last 20 minutes..."
read -p "Press any key to continue. "

find /var -mtime -20

echo "3.) Finding all files in /var that are regular files of zero length..."
read -p "Press any key to continue. "

find /var -size 0

echo "4.) Find all files in /dev that are not regular files and also not directories..."
read -p "Press any key to continue. "

find /dev ! -type f ! -type d -exec ls -l '{}' \;

echo "5.) Find all directories in /home that are not owned by root. Change permissions to ensure they have 711..."
read -p "Press any key to continue. "

find /home -type d ! -user root -exec chmod 711 '{}' \;

echo "6.) Find all regular files in /home that are not owned by root. Changed permissions to ensure they have 755..."
read -p "Press any key to continue. "

find /home -type f ! -user root -exec chmod 755 '{}' \;

echo "7.) Find all files in /etc that have changed in the last 5 days"
read -p "Press any key to continue. "

find /etc -mtime -5


