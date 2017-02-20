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
	int A[7] = {7, 6, 5, 3, 4, 2, 1};
    Heap H = Heap(7, A);  
    H.build_heap();
    H.print_heap();
    for (int i = 0; i < 7; i++) {
	    cout<<"Extracting Min"<<'\n';
	    int min = H.extract_min();
	    cout<<"Min extracted: "<<min<<'\n';
    }
    return 0;
}
