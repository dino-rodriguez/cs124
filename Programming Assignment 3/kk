#! /usr/bin/env python

# CS124, Programming Assignment 3
# Dino Rodriguez & Colton Gyulay

### Main

# libraries
import kk_library as KK
import sys

# debug mode
flag = 1

# if an inputfile is provided, print the KK difference to stdout
if len(sys.argv) > 1:
    A = []
    with open(sys.argv[1]) as f:
        for row in f:
            A.append(int(row))
    f.close()

    print KK.diffKK(A, 0)
