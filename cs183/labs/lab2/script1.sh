#!/bin/bash

for file in `find /usr/src/kernels/ -name *.h`; do

	grep -i magic $file

done | wc -l
