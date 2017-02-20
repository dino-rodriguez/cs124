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
#include <cmath>

using namespace std;

// class for complete and undirected graphs
class Complete_Undirected {

    private:
        // variables for number of vertices and dimension
        int vertices, dimension;
        float** V = NULL;

    public:
        // constructor, always takes in vertices
        Complete_Undirected(int v = 0, int d = 0) : vertices(v), dimension(d) {
        }
        // destructor, implicitly called and no arguments
        ~Complete_Undirected(void) {
        }

        // public methods
        float euclid();
        float gen_rand();
        float** generate_graph();
        int get_vertices();
        int get_dimension();
        float** get_graph();
        void print_graph();
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
    // seed random number generator with current machine time
    srand(time(NULL));

    // number of vertices
    int n = this->vertices;

    // initialize the 2-D array
    float** verts = new float* [n];
    for(int k = 0; k < n; k++)
        verts[k] = new float[n];

    if (this->dimension == 0) {
        // create vertices, build distances for each
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                verts[i][j] = this->gen_rand();
            }
        }
    } else {
        // create vertices, build distances for each
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
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
