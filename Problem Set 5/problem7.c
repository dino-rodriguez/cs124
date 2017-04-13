// problem 7, problem set 5
// Dino Rodriguez

// headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants
#define SIZE 15
#define BINS 1000000000

// prototypes
int part1();
int part2();

int main(void) {
    printf("PART 1 10x\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", part1());
    }
    printf("\n");
    printf("PART 2 10x\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", part2());
    }
    return 0;
}

int part1() {
    // build array before throwing balls
    int bins[SIZE+1] = {0};

    srand(time(NULL));
    int r = 0, acc = 0, prev_acc = 0, max = -1;

    // throw balls into bins
    for (int i = 0; i < BINS; i++) {
        // generate random number between 1 and 1B
        r = (rand() % BINS) + 1; // bucket ball is thrown into

        // if random number is greater number of balls thrown
        if (r > prev_acc) {
            // put in first bin
            bins[1]++;
            prev_acc++;
            continue;
        }

        else {
            acc = 0;

            for (int j = 1; j < SIZE; j++) {
                acc += bins[j]; // keep track of accumulator to use as probs

                // check if thrown into filled bucket
                if (r <= acc) {
                    bins[j] -= 1;
                    bins[j+1] += 1;
                    break;
                }
            }
        }

    }

    // find maximum load
    for (int i = 0; i < SIZE; i++) {
        if (bins[i] > 0) {
            max = i;
        }
    }

    return max;
}

int part2() {
    // build array before throwing balls
    int bins[SIZE+1] = {0};

    srand(time(NULL));
    int r1 = 0, r2 = 0, acc = 0, prev_acc = 0, max = -1;

    // throw balls into bins
    for (int i = 0; i < BINS; i++) {
        // generate random number between 1 and 1B
        r1 = (rand() % BINS) + 1; // bucket ball is thrown into
        r2 = (rand() % BINS) + 1; // bucket ball is thrown into

        // if random number is greater number of balls thrown
        if (r1 > prev_acc || r2 > prev_acc) {
            // put in first bin
            bins[1]++;
            prev_acc++;
            continue;
        }

        else {
            acc = 0;

            for (int j = 1; j < SIZE; j++) {
                acc += bins[j]; // keep track of accumulator to use as probs

                // check if thrown into filled bucket
                if (r1 <= acc || r2 <= acc) {
                    bins[j] -= 1;
                    bins[j+1] += 1;
                    break;
                }
            }
        }

    }

    // find maximum load
    for (int i = 0; i < SIZE; i++) {
        if (bins[i] > 0) {
            max = i;
        }
    }

    return max;
}
