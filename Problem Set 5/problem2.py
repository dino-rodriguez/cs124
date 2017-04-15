#!/usr/bin/python
# Dino Rodriguez

# libraries
import math
import operator as op
from decimal import *

# set precision
getcontext().prec = 40

# n choose x function for probability
def choose(n, x):
    x = min(x, n - x)
    if x == 0:
        return 1
    numerator = reduce(op.mul, xrange(n, n - x, -1))
    denominator = reduce(op.mul, xrange(1, x + 1))
    return numerator / denominator

# script to counting bloom filter probability of overflow for x bit counter
def bloomProb(x, n, m):

    k = math.ceil((float(m) / n) * math.log(2)) # optimal hashes
    probability = 0

    # find prob
    for i in range(2 ** x):
        probability += choose(n, i) * ((Decimal(k) / m) ** i) * ((1 - (Decimal(k) / m)) ** (n - i))

    return 1 - probability

# get probabilities for 3, 4, 5 bit counters
print bloomProb(3, 10 ** 5, 10 ** 6)
print bloomProb(4, 10 ** 5, 10 ** 6)
print bloomProb(5, 10 ** 5, 10 ** 6)
