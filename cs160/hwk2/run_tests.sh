#!/bin/bash

for i in {1..9}; do
	echo "Running test $i"
	./sdriver.pl -t trace0"$i".txt -s ./tsh -a \"-p\" > testoutput/"$i"
	./sdriver.pl -t trace0"$i".txt -s ./tshref -a \"-p\" > testoutput/"$i"ref
done

for i in {10..16}; do
	echo "Running test $i"
	./sdriver.pl -t trace"$i".txt -s ./tsh -a "-p" > testoutput/"$i"
	./sdriver.pl -t trace"$i".txt -s ./tshref -a "-p" > testoutput/"$i"ref
done
