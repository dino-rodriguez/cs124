#!/usr/bin/python
# Dino Rodriguez

# function to convert number to binary
def toBinary(n):
    return bin(n)[2:].zfill(8)

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

# function to convert message to ascii
def stringToASCII(s):
    asc = ""
    for c in s:
        asc = asc + str(toBinary(ord(c)))
    return int(asc, 2)

# encrypt message using RSA
def rsaEncode(n, e, s):
    x = stringToASCII(s)
    e_x = modExp(x, toBinary(e), n)
    return e_x

# encode message
print rsaEncode(46947848749720430529628739081,
           37267486263679235062064536973, "Give me an A")
