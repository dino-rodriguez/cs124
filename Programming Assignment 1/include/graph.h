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

using namespace std;

// class for complete and undirected graphs
class Complete_Undirected {

    private:
        // variables for number of vertices and dimension
        int vertices, dimension;
        float** V;

    public:
        // constructor, always takes in vertices
        Complete_Undirected(int v = 0, int d = 0) : vertices(v), dimension(d), V(NULL){
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
        float euclid();
        float gen_rand();
        float** generate_graph();
        int get_vertices();
        int get_dimension();
        float** get_graph();
        void print_graph();
        float mst_weight(float* dist);
        float prims();
        void overwrite(float** A);
        float confidence_interval();
};

// calculate euclidean distance of two points
float Complete_Undirected::euclid() {
    int k = this->dimension;
    float p1[k];
    float p2[k];
    float sum = 0;
    for (int i = 0; i < k; i++) {
        p1[i] = this->gen_rand();
        p2[i] = this->gen_rand();
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

// generate a random number from [0, 1]
float Complete_Undirected::gen_rand() {
    double r = ((double)rand() / RAND_MAX);
    return r;
}

// generate graph (seeding once to maintain distribution)
float** Complete_Undirected::generate_graph() {
    // number of vertices
    int n = this->vertices;

    // initialize the 2-D array
    float** verts = new float* [n];
    for(int k = 0; k < n; k++)
        verts[k] = new float[n];

    if (this->dimension == 0) {
        // // create vertices, build distances for each
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n && i != j; j++) {
        //         float dist = this->gen_rand();
        //         verts[i][j] = dist;
        //         verts[j][i] = dist;
        //     }
        // }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j++) {
                float dist = gen_rand();
                verts[i][j] = dist;
                verts[j][i] = dist;
            }
        }
    } else {
        // create vertices, build distances for each
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && i != j; j++) {
                // calculate distance with euclid
                float dist = this->euclid();
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
    Heap H;

    // Source Vertex
    entry S;
    S.vertex = 0;
    S.dist = 0;

    // insert source into heap
    H.insert(S);

    // set all vertices distances to infty and prevs to null
    for (int i = 0; i < vertices; ++i) {
        dist[i] = std::numeric_limits<float>::max();
        prev[i] = -1;
        set[i] = 0;
    }
    dist[S.vertex] = 0;

    while(H.get_size() > 0) {
        entry v = H.delete_min();
        set[v.vertex] = 1;
        for (int w = 0; w < vertices; w++) {
            if (set[w] == 1 || v.vertex == w) {
                continue;
            }
            if (dist[w] > V[v.vertex][w]) {
                dist[w] = V[v.vertex][w];
                prev[w] = v.vertex;
                entry _w;
                _w.vertex = w;
                _w.dist = dist[w];
                H.insert(_w);
            }
        }
    }
    float sum = 0;
    for (int i = 0; i < vertices; i++) {
        sum += dist[i];
    }
    return sum;
}

// float Complete_Undirected::mst_weight(float* dist) {
//     float sum = 0;
//     for (int i = 0; i < vertices; i++) {
//         sum += dist[i];
//     }
//     return sum;
// }

// soley for testing purposes only
void Complete_Undirected::overwrite(float** A) {
    V = A;
}

// function for calculating the confidence interval of predicted edge weights
float confidence_interval() {
    for (int i = 0; i < 1; i++)
    return 0;
}
