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
	Heap H = Heap();

	// Build a test heap
	entry A;
	A.vertex = 1;
	A.dist = 12;

	entry B;
	B.vertex = 2;
	B.dist = 5;

	entry C;
	C.vertex = 3;
	C.dist = 7;

	entry D;
	D.vertex = 4;
	D.dist = 19;

	// Testing to make sure insert works properly
	H.insert(A);
	H.insert(B);
	H.insert(C);
	H.insert(D);


	// Testing to make sure delete_min works properly
	int sz = H.get_size();
	for (int i = 0; i < sz; i++) {
		entry min = H.delete_min();
		cout<<"Vertex: "<<min.vertex<<'\n'<<"Value: "<<min.dist<<"\n\n";
	}
}
