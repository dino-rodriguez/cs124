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
    Heap(int s = 0, int* arr = 0) : sz(s), H(arr) {
        std::cout << "Heap constructor called." << '\n';
    }
    // destructor, implicitly called and no arguments
    ~Heap(void) {
        std::cout << "Heap deconstructor called." << '\n';
    }

    // methods
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void min_heapify(int i);
    void build_heap();
    void print_heap();
    void print_size();
    int peek();
    int extract_min();
};

int Heap::Parent(int i) {
    return floor(i/ 2) - 1;
}

int Heap::Left(int i) {
    return 2*i;
}

int Heap::Right(int i) {
    return 2*i + 1;
}

// ensure that i is the root of the max heap
void Heap::min_heapify(int i) {
    int smallest;
    int l = this->Left(i);
    int r = this->Right(i);
    if (l < this->sz && this->H[l] < this->H[i])
        smallest = l;
    else
        smallest = i;
    if (r < this->sz && this->H[r] < this->H[smallest])
        smallest = r;
    if (smallest != i) {
        int buf = this->H[i];
        this->H[i] = this->H[smallest];
        this->H[smallest] = buf;
        this->min_heapify(smallest);
    }
}

void Heap::build_heap() {
    for (int k = floor((this->sz)/2); k >= 1; k--) {
        this->min_heapify(k-1);
    }
}

void Heap::print_heap() {
    for (int i = 0; i < this->sz; i++) {
        cout<<this->H[i]<<',';
    }
    cout<<'\n';
}

void Heap::print_size() {
    cout<<this->sz<<'\n';
}

int Heap::peek() {
    if (this->sz > 0)
        return this->H[0];
    // if nothing is in the heap
    else
        return -1;
}

int Heap::extract_min() {
    // there must be at least one element on the heap
    assert(this->sz > 0);
    int min = this->H[0];

    // swap the root with the last element
    this->H[0] = this->H[this->sz - 1];
    this->sz -= 1;
    this->min_heapify(0);
    return min;
}
