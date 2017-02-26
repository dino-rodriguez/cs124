// Procedure Prim(G(V,E), s)
// v,w: vertices
// dist: array[V] of integer
// prev: array[V] of vertices
// S: set of vertices, initially empty
// H: priority heap of V
// H := {s : 0}
// for v ∈ V do
// dist[v] := ∞, prev[v] :=nil
// rof
// dist[s] := 0
// while H 6= 0/
// v := deletemin(h)
// S := S∪ {v}
// for (v,w) ∈ E and w ∈ V −S do
// if dist[w] > length(v,w)
// dist[w] := length(v,w), prev[w] := v, insert(w,dist[w],H)
// fi
// rof
// end while end Prim

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <heapNat.h>
#include <climits>

using namespace std;

int main(int argc, char* argv[]) {
	return 0;
}

struct entry {
	int node;
	int dist;
}

void Prims(G, s) {
	int* dist;
	int* prev;
	BinaryHeap H;
	int* S = H.vertices;
	
	// initialize the source node
	entry s;
	s.node = 0;
	s.dist = 0;
	H.insert(s);

	// set all vertices distances to infty and 
	for (int i = 0; i < G.get_length(); ++i) {
		dist[i] = INT_MAX;
		prev[i] = NULL;
	}
	dist[0] = 0;
	while(H.get_size() > 0) {
		entry v = H.deletemin();
		
	}


}