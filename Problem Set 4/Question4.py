# Coded by Dino Rodriguez
# Referenced code in Chapter 15 CLRS, "Rod Cutting" to devise
# a bottom-up solution

# libraries
import math

# import text and get all words
f = open("buffy.txt")
buffy = f.read().replace('\n', ' ').rstrip()
buffy = buffy.split(' ')

# function to compute the penalty of each possible grouping of words
def extra_space(words, M):
    n = len(words) # number of words

    # n lists to store all penalties for word combos
    P = [[float('inf') for y in xrange(n + 1)] for x in xrange(n + 1)]

    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            # optimization discussed in solution for nM
            if i - j + 1 <= math.ceil(M/2.0):
                # extra space
                E = M - (j - i) - len(reduce(lambda x, y: x + y, words[i - 1:j]))

                # cannot store, too many words on one line
                if E < 0:
                    continue
                # you are on the last line, cost-less
                elif j is n and E >= 0:
                    P[i][j] = 0
                # calculate cost as regular
                else:
                    P[i][j] = E**3

    return P

# function to computee the optimal arrangement of words and minimum penalty
def optimal(extra, M):
    n = len(extra)

    # list to store optimal penalty for word combos incrementally
    X = [0]
    W = [0]

    # bottom-Up build final array
    for j in range(1, n):
        X.append(float('inf'))
        W.append(float('inf'))

        # optimization discussed in solution for nM
        for i in range(max(1, j - int(math.ceil(M/2.0)) + 1), j + 1):
            if X[i - 1] + extra[i][j] < X[j]:
                X[j] = X[i - 1] + extra[i][j]
                W[j] = i
    return X, W

# function to print out the paragraph once we are done
def pretty_print(words, W, j):
    # start from second to last
    i = W[j]
    x = ''
    if i is 1:
        x = ''
    else:
        pretty_print(words, W, i - 1)
    print ' '.join(words[i-1:j])
    return x

# M = 72
extra = extra_space(buffy, 72)
(X, W) = optimal(extra, 72)
print '\nMinimum Penalty for M = ' + str(72) + ': ' + str(X[-1]) + '\n'
print pretty_print(buffy, W, len(buffy))

# M = 40
extra = extra_space(buffy, 40)
(X, W) = optimal(extra, 40)
print '\nMinimum Penalty for M = ' + str(40) + ': ' + str(X[-1]) + '\n'
print pretty_print(buffy, W, len(buffy))
