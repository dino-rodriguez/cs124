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
    // vector<bool> H_pointers;
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void swap(int a, int b);
    void heap_down(int i);
    void heap_up(int i);
    // void increase_key(int i, entry key);

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

    // // if vertex not in heap, create pointer
    // if (H_pointers.size() <= i.vertex) {
    //
    //     // insert into heap
    //     H_pointers.resize(i.vertex + 1, false);
    //     H_pointers[i.vertex] = true;
    //     H.push_back(i);
    //     heap_up(get_size() - 1);
    // }
    //
    // // if vertex in heap, update pointer
    // else if (H_pointers[i.vertex] == false) {
    //     H_pointers[i.vertex] = true;
        H.push_back(i);
        heap_up(get_size() - 1);
    //
    // }
    //
    // else if (H_pointers[i.vertex] == true) {
    //     increase_key(get_size() - 1, i);
    // }
    //
    // // insert into heap
    // // entry n;
    // // n.dist = std::numeric_limits<float>::infinity();;
    // // n.vertex = -1;
    // // H.push_back(n);

}

// void Heap::increase_key(int i, entry key) {
//     if (key.dist > H[i].dist) {
//         cout<<"Error: Key is greater than element in H."<<'\n';
//     }
//         H[i].dist = key.dist;
//
//         while (i > 0 && H[Parent(i)].dist > H[i].dist) {
//             swap(i, Parent(i));
//             i = Parent(i);
//         }
//
// }

entry Heap::delete_min() {
    entry min = H[0];
    H[0] = H.back();
    H.pop_back();
    heap_down(0);
    return min;

}
