# CS124, Programming Assignment 3
# Dino Rodriguez & Colton Gyulay

### Functions

# libraries
import random


# Generate a random set of numbers
    # s : size of output set
    # flag : int for testing
def randomSet(s, flag):

    random.seed() # seed random number generator
    A = []

    # generate list
    for i in range(s):
        A.append(random.randint(1, 10 ** 12))

    if flag == 1: print A

    return A


# Prepartition a set A into a partition set
    # A : set of integers
def prepartition(A):

    # TODO
    return 0


# Karmarkar-Karp algorithm, differencing approach
    # A : set of integers
    # flag : int for testing
def difKK(A, flag):

    # make sure set is big enough
    if len(A) <= 2:
        return -1

    if flag == 1: print A

    # get two max elements
    a_i = max(A)
    A.remove(a_i)
    a_j = max(A)
    A.remove(a_j)

    difference = abs(a_i - a_j) # difference of two elements

    # compute difference for all elements
    while a_i != 0 and a_j != 0:

        # insert new elements into list
        A.append(difference)
        A.append(0)

        if flag == 1: print A

        # get two max elements
        a_i = max(A)
        A.remove(a_i)
        a_j = max(A)
        A.remove(a_j)

        difference = abs(a_i - a_j) # difference of two elements

    return difference


# Repeatedly generate random solutions to the problem,
# as determined by the representation
    # P : set of integers after partitioning
    # flag : int for testing
    # max_iter : int to denote number of times to generate solution
    # n : size of solution sequence
def repRandom(S, n, max_iter, flag):

    for 1 to range(max_iter):
        S1 = randomSet(s)
        if difKK(S1, 0) < difKK(S, 0): S = S1

    return S
