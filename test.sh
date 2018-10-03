#!/bin/bash

rm -f error.txt
make clean 
make -j BACKEND=SQL 2> error.txt || view error.txt


