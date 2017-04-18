# CS124, Programming Assignment 3
# Dino Rodriguez & Colton Gyulay


### Tests

# libraries
import kk_library as KK
import kk as Main
import csv
import time
import progressbar
import timeit


# test differencing approach (maintaining order)
def diffKKTest():
    A = [10, 8, 7, 6, 5]
    residue = KK.diffKK(A, not Main.flag)
    assert(residue == 2)

# test prepartition conversion then differencing approach
def prepartitionTest():
    A = [10, 8, 7, 6, 5]
    P = [1, 2, 2, 4, 5]
    residue = KK.prepartitionResidue(A, P)
    assert(residue == 4)

# confirm that residuals of both methods given equivalent solutions line up
def residualsTest():
    A = KK.randomSet(10, not Main.flag)
    S = KK.randomStandardRep(A)
    P = KK.transformStandard(S)
    assert(KK.standardResidue(A, S) == KK.prepartitionResidue(A, P))


def algoTest():

    max_iter = 25000 # use 25000 for actual trials
    row = ["KK_results", "SRRR_results", "SRHC_results", "SRSA_results",
           "PRRR_results", "PRHC_results", "PRSA_results"]

    with open("data.csv", "wb") as csv_file:
        # build csv writer and progress bar
        writer = csv.writer(csv_file, delimiter=',')
        writer.writerow(row)
        bar = progressbar.ProgressBar()

        for i in bar(range(100)): # switch to 100 for actual trials
            # show progressbar
            time.sleep(0.02)

            # get row
            A = KK.randomSet(100, not Main.flag) # generate random A
            row[0] = KK.diffKK(A, not Main.flag) # run KK
            row[1] = KK.repRandom(A, max_iter, 's', not Main.flag)
            row[2] = KK.hillClimb(A, max_iter, 's', not Main.flag)
            row[3] = KK.simAnneal(A, max_iter, 's', not Main.flag)
            row[4] = KK.repRandom(A, max_iter, 'p', not Main.flag)
            row[5] = KK.hillClimb(A, max_iter, 'p', not Main.flag)
            row[6] = KK.simAnneal(A, max_iter, 'p', not Main.flag)

            # insert into data list
            writer.writerow(row)


### Running Tests

#diffKKTest()
#prepartitionTest()
#residualsTest()
algoTest()
