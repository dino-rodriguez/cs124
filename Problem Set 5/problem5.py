#!/usr/bin/python
# Dino Rodriguez

# libraries
import random

# Used CLRS as a reference when building some of these algorithms.

# function to convert number to binary
def toBinary(n):
    return bin(n)[2:]

# function to carry out modular exponentiation
def modExp(a,b,n):

    p = 0 # to keep track of loop invariant
    d = 1

    for i in range(len(b)):
        p = 2 * p # use to make sure that d = a^p mod n
        d = (d * d) % n # use repeated squaring with d

        # if on bit, need to multiply by base
        if int(b[i]) == 1:
            p = p + 1
            d = (d * a) % n

    return d

# function to find t and u for the Rabin-Miller Test
def findTandU(n):

    t = 1
    while (n - 1) > 2 ** t:
        u = (n - 1) / 2 ** t

        # confirm u is odd
        if u % 2 == 1:
            return u, t
        t += 1

    return -1

# function to find witness
def witness(a, n):

    # find proper u and t
    u, t = findTandU(n)
    print u, t
    m_prev = modExp(a, toBinary(u), n)

    # find witness
    for i in range(1, t + 1):
        m = (m_prev ** 2) % n

        # if nontrival square root detected, witness found
        if m == 1 and m_prev != 1 and m_prev != (n - 1):
            return a

        m_prev = m

    # if value is not 1, return composite like fermatt would
    if m != 1:
        return a

    return False

# run rabinMiller a number of times to drastically reduce probability of false pos
def rabinMiller(n, s):
    random.seed()
    for i in range(s):
        # gen random num
        a = random.randint(1, n - 1)
        w = witness(a, n)
        # check if witness
        if w:
            return w

    return False


# testing functions
print rabinMiller(636127, 4)
print rabinMiller(294409, 4)
