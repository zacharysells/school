#!/bin/bash

IFS=$'\n'
for user in `cat /etc/passwd`; do

	echo $user | awk -F: '{printf "%s %s ", $1, $3}'
	usr=`echo $user | awk -F: '{printf "%s", $1}'`
	for group in `cat /etc/group`; do
		echo $group | awk -F: '{print $4}' | grep -q $usr
		if [[ $? == 0 ]]; then 
			printf "%s " `echo $group | awk -F: '{print $1}'`
		fi
	done	 
	printf "\n" 

done
