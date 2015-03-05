#!/bin/bash

#dur=(`ps -u root -U root -N | awk '{print $3}'`)
procs=`ps -u root -U root -N | awk '{print $1}'`
#len=${#procs[@]}

for pid in $procs; do
	#echo $pid
	time=(`ps -o time $pid | sed -e 's/[:-]/ /g'`)
	min=${time[2]}
	#echo $min
	
	if [[ $min -gt "2" ]] ; then
		kill -9 $pid
	fi	

done

