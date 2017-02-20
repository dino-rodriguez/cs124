// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <assert.h>
#include "heap.h"
#include <unistd.h>

using namespace std;

int main(void) {
	int A[4] = {4, 3, 2, 1};
    Heap H = Heap(4, A);  
    H.build_heap();
    // cout<<"Extracting Min"<<'\n';
    // int min = H.extract_min();
    // cout<<"Min extracted: "<<min<<'\n';
    H.print_heap();
    return 0;
}
