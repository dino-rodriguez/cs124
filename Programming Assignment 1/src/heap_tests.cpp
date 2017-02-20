// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <assert.h>
#include "heap.h"

using namespace std;

int main(void) {
	int A[6] = {2, 1, 3, 4, 5, 6};
    Heap H = Heap(6, A);  
    H.print_heap();
    H.build_heap();
    H.print_heap();
    cout<<"Extracting Min"<<'\n';
    int min = H.extract_min();
    cout<<"Min extracted: "<<min<<'\n';
    H.print_heap();
    return 0;
}
