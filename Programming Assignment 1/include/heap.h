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
#include <limits>

using namespace std;

struct entry {
    int vertex;
    float dist;
};


class Heap {

private:
    // variables for number of vertices and dimension
    vector<entry> H;
    vector<entry*> H_pointers;
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void swap(int a, int b);
    void heap_down(int i);
    void heap_up(int i);

public:
    // constructor, always takes in vertices
    Heap(void) {}
    // destructor, implicitly called and no arguments
    ~Heap(void) {}
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

    // if vertex not in heap, create pointer
    if (H_pointers.size() <= i.vertex) {
        // resize array for proper index
        while (H_pointers.size() <= i.vertex) {
            H_pointers.push_back(new entry);
            H_pointers.back() -> vertex = -1;
            H_pointers.back() -> dist = std::numeric_limits<float>::infinity();
        }

        // insert into heap
        H.push_back(i);
        heap_up(get_size() - 1);

        // point to new element in heap
        H_pointers.back() -> vertex = i.vertex;
        H_pointers.back() -> dist = i.dist;
    }

    // if vertex in heap, update pointer
    else if (H_pointers[i.vertex] -> dist > i.dist){
        cout<<"In heap"<<'\n';
        H_pointers[i.vertex] -> vertex = i.vertex;
        H_pointers[i.vertex] -> dist = i.dist;
    }

}

entry Heap::delete_min() {
    entry min = H[0];
    H[0] = H.back();
    H.pop_back();
    heap_down(0);
    return min;

}
