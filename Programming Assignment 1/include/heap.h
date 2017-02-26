/*
 * Header file for min heap structure.
 *
 * Made by SJ Kim and Dino Rodriguez.
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

struct entry {
    int vertex;
    int dist;
};


class Heap {

private:
    // variables for number of vertices and dimension
    vector<entry> H;
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void swap(int a, int b);
    void heap_down(int i);
    void heap_up(int i);

public:
    // constructor, always takes in vertices
    Heap(void) {
        std::cout << "Heap constructor called." << '\n';
    }
    // destructor, implicitly called and no arguments
    ~Heap(void) {
        std::cout << "Heap deconstructor called." << '\n';
    }
    int get_size() {
        return H.size();
    }
    void insert(entry i);
    entry delete_min();
};

int Heap::Parent(int i) {
    return (i - 1)/2;
}

int Heap::Left(int i) {
    return 2*i + 1;

}

int Heap::Right(int i) {
    return 2*i + 2;
}

void Heap::swap(int a, int b) {
    entry temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

void Heap::heap_down(int i) {
    int l = Left(i);
    int r = Right(i);
    int small = i;

    if (l < get_size() && H[l].dist < H[i].dist) 
        small = l;
    if (r < get_size() && H[r].dist < H[small].dist)
        small = r;
    if (small != i) {
        swap(i, small);
        heap_down(small);
    }
}

void Heap::heap_up(int i) {
    int p = Parent(i);
    if (i && H[p].dist > H[i].dist) {
        swap(i, p);
        heap_up(p);
    } 
}

void Heap::insert(entry i) {
    H.push_back(i);
    heap_up(get_size() -1);
}

entry Heap::delete_min() {
    int sz = get_size();
    assert(sz > 0);
    entry min = H[0];
    H[0] = H.back();
    H.pop_back();
    heap_down(0);
    return min;

}

