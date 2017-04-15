# CS124, Programming Assignment 3
# Dino Rodriguez & Colton Gyulay


### Tests

# libraries
import kk_library as KK
import kk as Main

def randomSetTest():
    return KK.randomSet(100, not Main.flag)

def difKKTest():
    A = [10, 8, 7, 6, 5]
    residue = KK.difKK(A, not Main.flag)

# running tests
randomSetTest()
difKKTest()
