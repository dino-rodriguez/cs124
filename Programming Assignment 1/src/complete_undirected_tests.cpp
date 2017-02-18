// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <assert.h>
#include "graph.h"

using namespace std;

int main(void) {
    Complete_Undirected(5, 1);
    float n = Complete_Undirected.gen_rand();
    std::cout << n << '\n';
    return 0;
}
