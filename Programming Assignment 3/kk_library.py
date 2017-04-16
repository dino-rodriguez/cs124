# CS124, Programming Assignment 3
# Dino Rodriguez & Colton Gyulay

### Functions

# libraries
import random
import math


# Generate a random set of numbers
    # s : size of output set
    # flag : int for testing
def randomSet(s, flag):
    random.seed()
    A = []

    # generate list
    for i in range(s):
        A.append(random.randint(1, 10 ** 12))

    if flag == 1: print A

    return A


# Karmarkar-Karp algorithm, differencing approach
    # A : set of integers
    # flag : int for testing
def diffKK(A, flag):
    # make sure set is big enough
    A1 = A[:]
    if len(A1) <= 2:
        return -1

    if flag == 1: print A1

    # get two max elements
    a_i = max(A1)
    A1.remove(a_i)
    a_j = max(A1)
    A1.remove(a_j)

    difference = abs(a_i - a_j) # difference of two elements

    # compute difference for all elements
    while a_i != 0 and a_j != 0:

        # insert new elements into list
        A1.append(difference)
        A1.append(0)

        if flag == 1: print A1

        # get two max elements
        a_i = max(A1)
        A1.remove(a_i)
        a_j = max(A1)
        A1.remove(a_j)

        difference = abs(a_i - a_j) # difference of two elements

    return difference


# Return a random prepartitioning representation for a set of numbers A
    # A : set of integers
def randomPrepartitionRep(A):
    n = len(A)
    return [random.choice(range(1, n + 1)) for i in range(n)]


# Return a random standard representation for a set of numbers A
    # A : set of integers
def randomStandardRep(A):
    return [random.choice([-1, 1]) for i in range(len(A))]


# Calculate the residue for a set of numbers A while enforcing prepartioning
# representation P
    # A : set of integers
    # P : set of integers over [1, n]
def prepartitionResidue(A, P):
    assert(len(A) == len(P))

    # first convert to KK digestible format
    n = len(A)
    A1 = [0] * n
    for i, p in enumerate(P):
        A1[p - 1] += A[i]

    # return value from KK
    return abs(diffKK(A1, 0))


# Calculate the residue for a set of numbers A while enforcing standard
# representation S
    # A : set of integers
    # S : set of integers, composed only of -1 or 1
def standardResidue(A, S):
    assert(len(A) == len(S))

    # sum of a_i * s_i
    return abs(sum([a * s for a, s in zip(A, S)]))


# Calculate a random 'neighbor' for a prepartitioning representation P
    # P : set of integers over [1, n]
def prepartitionNeighbor(P):
    P1 = P[:]
    n = len(P1)
    i, j = random.sample(range(1, n + 1), 2)
    i -= 1 # offset index by 1 as we're sampling from [1, n] inclusive
    P1[i] = j

    return P1


# Calculate a random 'neighbor' for a standard representation S
    # S : set of integers, composed only of -1 or 1
def standardNeighbor(S):
    S1 = S[:]
    n = len(S1)
    i, j = random.sample(S1, 2)

    # switch element i
    S1[i] = -S1[i]

    # with prob 1/2, switch element j
    if random.uniform(0, 1) < 0.5:
        S1[j] = -S1[j]

    return S1


# Helper method returns corresponding generation, residue, and neighbor
# functions for a specific representation type type_
    # type_ : string to denote representation type, 's' or 'p'
def gatherFns(type_):
    if type_ == 's':
        gen_fn = randomStandardRep
        residue_fn = standardResidue
        neighbor_fn = standardNeighbor
    elif type_ == 'p':
        gen_fn = randomPrepartitionRep
        residue_fn = prepartitionResidue
        neighbor_fn = prepartitionNeighbor
    else:
        raise ValueError("Invalid representation type, must be 'p' or 's'")

    return gen_fn, residue_fn, neighbor_fn


# Repeatedly generate random solutions to the problem, as determined by the
# representation
    # A : set of integers to partition
    # max_iter : int to denote number of times to generate solution
    # type_ : string to denote representation type, 's' or 'p'
    # flag : int for testing
def repRandom(A, max_iter, type_, flag):
    gen, residue, neighbor = gatherFns(type_)
    S = gen(A)

    for i in range(max_iter):
        S1 = gen(A)
        if residue(A, S1) < residue(A, S):
            S = S1

    return residue(A, S)


# Generate a random solution, then attempt to improve it through moves to
# better neighbors
    # A : set of integers to partition
    # max_iter : int to denote number of times to generate solution
    # type_ : string to denote representation type, 's' or 'p'
    # flag : int for testing
def hillClimb(A, max_iter, type_, flag):
    gen, residue, neighbor = gatherFns(type_)
    S = gen(A)

    for i in range(max_iter):
        S1 = neighbor(S)
        if residue(A, S1) < residue(A, S):
            S = S1

    return residue(A, S)


# Generate a random solution, then attempt to improve it through moves to
# neighbors that are not always better
    # A : set of integers to partition
    # max_iter : int to denote number of times to generate solution
    # type_ : string to denote representation type, 's' or 'p'
    # flag : int for testing
def simAnneal(A, max_iter, type_, flag):
    gen, residue, neighbor = gatherFns(type_)
    S = gen(A)
    S11 = S[:]

    def T(i):
        return (10 ** 10) * (0.8 ** (i // 300))

    for i in range(max_iter):
        S1 = neighbor(S)
        if residue(A, S1) < residue(A, S):
            S = S1
        # TODO: ensure probability to switch to worse neighbor is correct
        elif random.uniform(0, 1) < math.exp(-(residue(A, S1) - residue(A, S)) / T(i)):
            S = S1
        if residue(A, S) < residue(A, S11):
            S11 = S

    return residue(A, S11)
