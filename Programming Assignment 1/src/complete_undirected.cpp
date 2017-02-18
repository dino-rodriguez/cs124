#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int p;
	struct Node* next;
}

struct AList {
	struct Node* head;
}

struct cuGraph {
	private: 
		int Vertices;
		struct AList* lst;
}

struct Node* createNode(int p) {
	
}