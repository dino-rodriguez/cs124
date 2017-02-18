#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
	int val;
	struct Node* next;
};

struct AList {
	struct Node* head;
};

class Graph {
	private: 
		int V;
		struct AList* lst;
	public: 
		Graph(int Vert) {
			this->V = V;
			lst = new AList [Vert];
			for (int i = 0; i < Vert; i++)
				lst[i].head = NULL;

		}
		Node* createNode(int val) {
			Node* node = new Node;
			node->val = val;
			node->next = NULL;
			return node;
		}
		void createEdge(int src, int sink) {
			Node* node = createNode(sink);
			node->next = lst[src].head;
			lst[src].head = node;
			node = createNode(src);
			node->next = lst[sink].head;
			lst[sink].head = node;
		}

};

// int main(void) {
// 	Graph  
// }

