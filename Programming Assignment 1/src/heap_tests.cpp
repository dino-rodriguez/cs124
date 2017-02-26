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
	H.insert(5);
	H.insert(1);
	H.insert(4);
	H.insert(2);
	H.insert(3);
	H.print();
	for (int i = 0; i < 5; i++) {
		int min = H.extract_min();
		cout<<min<<'\n';
	}
}



