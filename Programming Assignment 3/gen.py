'''Generate a sample inputfile for testing.
'''

import random
import kk_library as KK

A = KK.randomSet(100, 0)
f = open('inputfile.txt', 'w')

for i in A:
    f.write(str(i) + '\n')

f.close()
