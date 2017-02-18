// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <assert.h>
#include "graph.h"

using namespace std;

int main(void) {
    Complete_Undirected C = Complete_Undirected(5, 1);
    C.generate_graph();
    double r = C.gen_rand();
    cout<<r<<'\n';

    return 0;
}
