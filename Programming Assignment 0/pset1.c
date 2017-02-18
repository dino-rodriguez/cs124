/**
 * CS 124
 * Problem Set 1, #2
 * Harvard ID: 30940040
 */

// libraries
#include <stdio.h>
#include <time.h>

// constants
#define OVERFLOW 65536
#define MAX_TIME 60

// matrix struct that represents:
// | a b |
// | c d |
typedef struct Matrix {
    int a;
    int b;
    int c;
    int d;
} Matrix;

// struct to return tuple containing timings and fib number
typedef struct Fib_Tuple {
    int fib; // store fibonacci number
    double elapsed; // store seconds elapsed over function
    int n_per_sec[MAX_TIME]; // store n for every second in a minute
} Fib_Tuple;

// prototypes
int fib1(int n);
Fib_Tuple fib2(int n);
Fib_Tuple fib3(int n);
Matrix matrix_mult(Matrix A, Matrix B);

// global variables (for timing)
clock_t start, end;
double seconds;

int main(void) {

    // test fib1
    printf("\nRECURSIVE ALGORITHM\n");
    start = clock();
    printf("Fib n = %d: %d\n", 48, fib1(48));
    end = clock();
    seconds = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time elapsed (manual stop at 60 seconds): %f\n", seconds);

    // test fib2
    printf("\nITERATIVE ALGORITHM\n");
    Fib_Tuple fib_iter = fib2(1000000000);
    printf("Fib n = %d: %d\n", 10000, fib_iter.fib);
    printf("Time Elapsed (autostop at 60 seconds): %f\n", fib_iter.elapsed);
    printf("Nth Fib per Second:\n");
    for (int i = 0; i < MAX_TIME; i++) {
        printf("Second %d: n = %d\n", i + 1, fib_iter.n_per_sec[i]);
    }

    // test fib3
    printf("\nMATRIX ALGORITHM\n");
    Fib_Tuple fib_matrix = fib3(1000000000);
    printf("Fib n = %d: %d\n", 10000, fib_matrix.fib);
    printf("Time Elapsed (autostop at 60 seconds): %f\n", fib_matrix.elapsed);
    printf("Nth Fib per Second:\n");
    for (int i = 0; i < MAX_TIME; i++) {
        printf("Second %d: n = %d\n", i + 1, fib_matrix.n_per_sec[i]);
    }

    return 0;
}

// recursive fibonacci function
int fib1(int n) {
    // base case 1
    if (n == 0) {
        return 0;
    }
    // base case 2
    else if (n == 1) {
        return 1;
    }
    // recursive case
    else {
        return (fib1(n - 1) + fib1(n - 2)) % OVERFLOW;
    }
}

// dp fibonacci function
Fib_Tuple fib2(int n) {
    // start timer, set empty tuple
    start = clock();
    Fib_Tuple t = {0, 0, {0}};

    // base case 1
    if (n == 0) {
        // end timer
        end = clock();
        seconds = ((double)(end - start))/CLOCKS_PER_SEC;

        // store in tuple
        t.fib = 0;
        t.elapsed = seconds;
        return t;
    }

    // base case 2
    else if (n == 1) {
        // end timer
        end = clock();
        seconds = ((double)(end - start))/CLOCKS_PER_SEC;

        // store in tuple
        t.fib = 0;
        t.elapsed = seconds;

        return t;
    }

    // variables to store calculated fibonacci numbers
    int a = 0, b = 1, sec_index = 0, temp; // sec_index holds the indices for timings array

    // iterative case
    for (int i = 2; i <= n; i++) {
        temp = a;
        a = b;
        b = (temp + a) % OVERFLOW;

        // end timer
        end = clock();
        seconds = ((double)(end - start))/CLOCKS_PER_SEC;

        if (seconds > sec_index + 1) {
            // store n for each second
            t.n_per_sec[sec_index++] = i;

            // stop the function at one minute
            if (sec_index >= MAX_TIME) {

                // store in tuple
                t.fib = b;
                t.elapsed = seconds;

                return t;
            }
        }
    }

    // store in tuple
    t.fib = b;
    t.elapsed = seconds;

    return t;
}

// matrix fibonacci function
Fib_Tuple fib3(int n) {
    // start timer, set empty tuple
    start = clock();
    Fib_Tuple t = {0, 0, {0}};

    // base case 1
    if (n == 0) {
        // end timer
        end = clock();
        seconds = ((double)(end - start))/CLOCKS_PER_SEC;

        // store in tuple
        t.fib = 0;
        t.elapsed = seconds;

        return t;
    }

    // base case 2
    else if (n == 1) {
        // end timer
        end = clock();
        seconds = ((double)(end - start))/CLOCKS_PER_SEC;

        // store in tuple
        t.fib = 0;
        t.elapsed = seconds;

        return t;
    }

    // starting matrices
    Matrix A = {0, 1, 1, 1};
    Matrix B = {0, 0, 1, 0};
    Matrix C = A;
    int sec_index = 0; // sec_index holds the indices for timings array

    for (int i = 2; i <= n; i++) {
        // calculate matrix multiplication for left-side matrix
        C = matrix_mult(C, A);

        // end timer
        end = clock();
        seconds = ((double)(end - start))/CLOCKS_PER_SEC;

        if (seconds > sec_index + 1) {
            // store n for each second
            t.n_per_sec[sec_index++] = i;

            // stop the function at one minute
            if (sec_index >= MAX_TIME) {
                // get nth fibonacci
                C = matrix_mult(C, B);

                // store in tuple
                t.fib = C.a;
                t.elapsed = seconds;

                return t;
            }
        }

        /**
         * For checking integer overflow, commented out for speed because
         * already calculated at n = 47

        if (matrix_mult(C, B).a < 0) {
            printf("INTEGER OVERFLOW: N = ");
            return i;
        }

        */
    }

    // get nth fibonacci
    C = matrix_mult(C, B);

    // store in tuple
    t.fib = C.a;
    t.elapsed = seconds;

    return t;
}

// matrix multiplication
Matrix matrix_mult(Matrix A, Matrix B) {
    Matrix C = {
        (((A.a * B.a) % OVERFLOW) + ((A.b * B.c) % OVERFLOW)) % OVERFLOW,
        (((A.a * B.b) % OVERFLOW) + ((A.b * B.d) % OVERFLOW)) % OVERFLOW,
        (((A.c * B.a) % OVERFLOW) + ((A.d * B.c) % OVERFLOW)) % OVERFLOW,
        (((A.c * B.b) % OVERFLOW) + ((A.d * B.d) % OVERFLOW)) % OVERFLOW
    };

    return C;
}
