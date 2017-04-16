# CS124, Programming Assignment 3
# Dino Rodriguez & Colton Gyulay


### Tests

# libraries
import kk_library as KK
import kk as Main


def randomSetTest():
    return KK.randomSet(100, not Main.flag)


def diffKKTest():
    A = [10, 8, 7, 6, 5]
    residue = KK.diffKK(A, not Main.flag)


def prepartitionTest():
    A = [10, 8, 7, 6, 5]
    P = [1, 2, 2, 4, 5]
    residue = KK.prepartitionResidue(A, P)


def algoTest():
    # TODO: timing and avgs across trials for all algorithms

    for i in range(1): # switch to 100 for actual trials
        max_iter = 1000 # use 25000 for actual trials
        A = KK.randomSet(100, not Main.flag)
        kk_res = KK.diffKK(A, not Main.flag)

        s_rand_res = KK.repRandom(A, max_iter, 's', not Main.flag)
        s_hill_res = KK.hillClimb(A, max_iter, 's', not Main.flag)
        s_anneal_res = KK.simAnneal(A, max_iter, 's', not Main.flag)

        p_rand_res = KK.repRandom(A, max_iter, 'p', not Main.flag)
        p_hill_res = KK.hillClimb(A, max_iter, 'p', not Main.flag)
        p_anneal_res = KK.simAnneal(A, max_iter, 'p', not Main.flag)

        print 'KK: {}'.format(kk_res)

        print 'Standard representation repeated random: {}'.format(s_rand_res)
        print 'Standard representation hill climbing: {}'.format(s_hill_res)
        print 'Standard representation simulated annealing: {}'.format(s_anneal_res)

        print 'Prepartioning representation repeated random: {}'.format(p_rand_res)
        print 'Prepartioning representation hill climbing: {}'.format(p_hill_res)
        print 'Prepartioning representation simulated annealing: {}'.format(p_anneal_res)


# running tests
randomSetTest()
diffKKTest()
prepartitionTest()
algoTest()
