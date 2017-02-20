// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <assert.h>
#include "heap.h"

using namespace std;

int main(void) {
	int A[6] = {2, 1, 4, 3, 6, 5};
    Heap H = Heap(6, A);
    
    return 0;
}
