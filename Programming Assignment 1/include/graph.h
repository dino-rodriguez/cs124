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

using namespace std;

// class for complete and undirected graphs
class Complete_Undirected {

private:
    // variables for number of vertices and dimension
    int vertices, dimension;

public:
    // constructor, always takes in vertices
    Complete_Undirected(int v = 0, int d = 1) : vertices(v), dimension(d) {
        std::cout << "Complete_Undirected constructor called." << '\n';
    }
    // destructor, implicitly called and no arguments
    ~Complete_Undirected(void) {
        std::cout << "Complete_Undirected deconstructor called." << '\n';
    }

    // public methods
    float euclid();
    float gen_rand();
    void insert_edges(int, int);
    void generate_graph();
    int get_vertices();
    int get_dimension();
    void print_graph();
};

float Complete_Undirected::euclid() {


}

float Complete_Undirected::gen_rand() {
    // Seed random number generator with current machine time
    srand(time(NULL));

    // Generate a random number from [0, 1]
    return (float)(rand() % RAND_MAX);
}

void Complete_Undirected::insert_edges(int v, int w) {

}

void Complete_Undirected::generate_graph() {

    // instantiate arrays of vertices and distances
    int V[vertices];

    // initialize V
    for (int i = 0; i < vertices; i++) {
        int D[vertices];
        V[i] = -1;

        // create vertices, build distances for each
        for (int j = 0; j < vertices; j++) {
            D[j] = rand();
        }

    }

    // insert edges into E


}

int Complete_Undirected::get_vertices() {

}

int Complete_Undirected::get_dimension() {

}

void Complete_Undirected::print_graph() {

}
