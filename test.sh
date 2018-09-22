#!/bin/bash

rm -f error.txt
make clean 
make -j 2> error.txt || view error.txt


