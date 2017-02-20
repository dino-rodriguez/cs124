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
    Heap(int s = 0) : sz(s) {
        std::cout << "Heap constructor called." << '\n';
    }
    // destructor, implicitly called and no arguments
    ~Heap(void) {
        std::cout << "Heap deconstructor called." << '\n';
    }
    int findParent(int i);
    int Left(int i);
    int Right(int i);
    void minHeapify();
    void buildHeap();
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

void minHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
}
