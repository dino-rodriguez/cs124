/*
 * Header file for graph structure.
 *
 * Made by SJ Kim and Dino Rodriguez.
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <typeinfo>
#include <vector>
#include "heap.h"
#include <sys/time.h>
#include <unistd.h>
#include <limits>
#include <random>

using namespace std;


// class for complete and undirected graphs
class Complete_Undirected {

    private:
        // variables for number of vertices and dimension
        int vertices, dimension;
        float** V;
        float kn;

    public:
        // constructor, always takes in vertices
        Complete_Undirected(int v = 0, int d = 0) : vertices(v), dimension(d), V(NULL), kn(-1){
            // seeding in terms of milliseconds
            struct timeval t1;
            gettimeofday(&t1, NULL);
            srand(t1.tv_usec * t1.tv_sec);
        }
        // destructor, implicitly called and no arguments
        ~Complete_Undirected(void) {
            // ensure that srand is called with a different millisecond seed
            usleep(1000);
        }

        // public methods
        void dim_kn();
        float euclid(float p1[], float p2[]);
        float gen_rand();
        float** generate_graph(bool remove_flag);
        int get_vertices();
        int get_dimension();
        float** get_graph();
        void print_graph();
        float mst_weight(float* dist);
        float prims();
        void overwrite(float** A);
};

// function to calculate cutoff threshold for edge throwaway
void Complete_Undirected::dim_kn() {

    float y_gen[4];

    // equation modeling weight for dimension 0
    y_gen[0] = float(6 * vertices)/(5 * vertices + 1);

    // equation modeling weight for dimension 2
    y_gen[1] = (2.0 * sqrt(vertices)) / 3;

    // equation modeling weight for dimension 3
    y_gen[2] = (5.0/6) * powf(vertices, 0.64);

    // equation modeling weight for dimension 4
    y_gen[3] = (5.0/6) * powf(vertices, 0.73);

    float avg_edge = y_gen[0]/(vertices - 1); // estimated mean edge

    // calculate std deviation for higher dimensions
    if (dimension != 0) {
        // calcluate proper average for dimension
        avg_edge = y_gen[dimension - 1]/(vertices - 1);
    }

    float upper_confidence = avg_edge * 4;
    cout<<"avg " <<upper_confidence<<'\n';
    // assign to private var
    kn = upper_confidence;
}


// calculate euclidean distance of two points
float Complete_Undirected::euclid(float p1[], float p2[]) {
    int k = this->dimension;
    float sum = 0;
    for (int i = 0; i < k; i++) {
        float diff = p2[i] - p1[i];
        sum += powf(diff, 2.0);
    }
    float distance = sqrt(sum);
    return distance;
}


// generate a random number from [0, 1]
float Complete_Undirected::gen_rand() {
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return r;
}


// generate graph (seeding once to maintain distribution)
// takes in flag to consider removing edges
float** Complete_Undirected::generate_graph(bool remove_flag) {
    // number of vertices
    int n = this->vertices;
    dim_kn(); // set edge cutoff threshold

    // initialize the 2-D array
    float** verts = new float* [n];
    for(int k = 0; k < n; k++)
        verts[k] = new float[n];

    if (this->dimension == 0) {
        // // create vertices, build distances for each
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && i != j; j++) {

                float dist = this->gen_rand();
                
                verts[i][j] = dist;
                verts[j][i] = dist;
            }
        }

    } else {
        // allocate space for array of nodes of a given dimension
        float nodes[this->vertices][this->dimension];

        // create vertices
        for (int i = 0; i < n; i++) {
            // generate point
            for (int j = 0; j < this->dimension; j++) {
                nodes[i][j] = this->gen_rand();
            }
        }

        // build distances for each edge
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && i != j; j++) {

                // calculate distance with euclid
                float dist = euclid(nodes[i], nodes[j]);

                // consider removing edges
                if (remove_flag == true && dist > kn) {
                    sum = sum + 1;
                    dist = -1;
                }

                // assign to edge to both vertices because undirected
                verts[i][j] = dist;
                verts[j][i] = dist;
            }
        }
    }

    this->V = verts;
    return V;
}


// return the vertice count of the graph
int Complete_Undirected::get_vertices() {
    return this->vertices;
}


// return the dimension of the graph
int Complete_Undirected::get_dimension() {
    return this->dimension;
}


// return the graph
float** Complete_Undirected::get_graph() {
    return this->V;
}


// print the graph
void Complete_Undirected::print_graph() {

    // make sure graph is generated
    if (this->V == NULL) {
        cout<<"NULL\n\n";
    }
    else {
        for (int i = 0; i < this->vertices; i++) {
            cout<<"Vertex: "<<i<<'\n';
            for (int j = 0; j < this->vertices; j++) {
                cout<<"("<<i<<", "<<j<<") -> "<<this->V[i][j]<<'\n';
            }
            cout<<"\n\n";
        }
    }
}


// run prims algorithm and return the MST of the graph
float Complete_Undirected::prims() {
    float dist[vertices];
    int prev[vertices];
    int set[vertices];
    Heap H = Heap();

    // Source Vertex
    entry S;
    S.vertex = 0;
    S.dist = 0;

    // insert source into heap
    H.insert(S);

    // set all vertices distances to infty and prevs to null
    for (int i = 0; i < vertices; i++) {
        dist[i] = std::numeric_limits<float>::infinity();
        prev[i] = -1;
        set[i] = 0;
    }
    dist[S.vertex] = 0;

    // while the heap is not empty
    while(H.get_size() > 0) {
        entry v = H.delete_min();
        set[v.vertex] = 1;
        // update all edges to have the new minimum edge weight
        for (int w = 0; w < vertices; w++) {
            // if in current tree, disregard
            if (set[w] == 1 || v.vertex == w || V[v.vertex][w] == -1) {
                continue;
            }
            // else consider if smaller edge than stored in heap
            else if (dist[w] > V[v.vertex][w]) {
                dist[w] = V[v.vertex][w];
                prev[w] = v.vertex;
                entry _w;
                _w.vertex = w;
                _w.dist = dist[w];
                H.insert(_w);
            }
        }
    }
    return mst_weight(dist);
}


// return the weight of the mst
float Complete_Undirected::mst_weight(float* dist) {
    float sum = 0;
    for (int i = 0; i < vertices; i++) {
        sum += dist[i];
    }
    return sum;
}


// soley for testing purposes only
void Complete_Undirected::overwrite(float** A) {
    V = A;
}
