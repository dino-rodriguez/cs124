/*
 * Header file for graph structure.
 *
 * Made by SJ Kim and Dino Rodriguez.
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>


using namespace std;

// class for complete and undirected graphs
class Heap {

private:
    // variables for number of vertices and dimension
    int sz;
    int* H;

public:
    // constructor, always takes in vertices
    Heap(int s = 0, int* arr) : sz(s), H(arr) {
        std::cout << "Heap constructor called." << '\n';
    }
    // destructor, implicitly called and no arguments
    ~Heap(void) {
        std::cout << "Heap deconstructor called." << '\n';
    }
    int findParent(int i);
    int Left(int i);
    int Right(int i);
    // SJ
    void minHeapify();
    void buildHeap();

    // Dino
    void peak();
    void extractMax();
    void insert();
};

int Parent(int i) {
    return floor(i / 2);
}

int Left(int i) {
    return 2*i;
}

int Right(int i) {
    return 2*i + 1;
}

// ensure that i is the root of the max heap
void minHeapify(int i) {
    int smallest;
    int l = Left(i);
    int r = Right(i);
    if (l < sz && this->H[l] < this->H[i])
        smallest = l;
    else 
        smallest = i;
    if (r < sz && this->H[r] < this->H[smallest])
        smallest = r;
    if (smallest != i) {
        int buf = this->H[i];
        this->H[i] = this->H[smallest];
        this->H[smallest] = buf;
        minHeapify(smallest);
    }
}

void buildHeap() {
    for (int k = floor(sz/2); i > 1; i--) {
        minHeapify(k);
    }
}


