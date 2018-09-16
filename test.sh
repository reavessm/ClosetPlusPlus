#!/bin/bash

rm -f error.txt
#make clean 
make 2> error.txt
view error.txt


