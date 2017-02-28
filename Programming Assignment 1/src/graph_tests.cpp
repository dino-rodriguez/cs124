// libraries
#include "graph.h"
#include <assert.h>

using namespace std;

int main(void) {
    // // generate graphs of each dimension
    Complete_Undirected D0 = Complete_Undirected(10, 0);
    // Complete_Undirected D1 = Complete_Undirected(10, 1);
    // Complete_Undirected D2 = Complete_Undirected(10, 2);
    // Complete_Undirected D3 = Complete_Undirected(10, 3);
    // Complete_Undirected D4 = Complete_Undirected(10, 4);

    // // get vertice numbers
    // assert(D0.get_vertices() == 10);
    // assert(D4.get_vertices() == 10);

    // // get dimension
    // assert(D0.get_dimension() == 0);
    // assert(D4.get_dimension() == 4);

    // // get graph, print location in memory
    // assert(D0.generate_graph() == D0.get_graph());

    // // print some graphs
    // D1.generate_graph();
    // D4.generate_graph();

    // // cout<<"D0\n";
    // // D0.print_graph();
    // // cout<<"D1\n";
    // // D1.print_graph();
    // // cout<<"D2\n";
    // // D2.print_graph();
    // // cout<<"D4\n";
    // // D4.print_graph();

    // // testing a number of different custom trees

    // V = 2, D = 0
    // Complete_Undirected G = Complete_Undirected(2, 0);
    // G.generate_graph();
    // // initialize the 2-D array
    // float** A = new float* [2];
    // for(int k = 0; k < 2; k++)
    //     A[k] = new float[2];

    // A[0][1] = 1;
    // A[1][0] = 1;
    // A[0][0] = 0;
    // A[1][1] = 0;
    // G.overwrite(A);
    // G.print_graph();
    // G.prims();

    // // V = 3, D = 0
    // Complete_Undirected D2F = Complete_Undirected(3, 0);
    // D2F.generate_graph();

    // // initialize the 2-D array
    // float** A3 = new float* [3];
    // for(int k = 0; k < 3; k++)
    //     A3[k] = new float[3];
    // A3[0][0] = 0;
    // A3[1][1] = 0;
    // A3[2][2] = 0;
    // A3[0][1] = 1;
    // A3[1][0] = 1;
    // A3[0][2] = 2;
    // A3[2][0] = 2;
    // A3[1][2] = 3;
    // A3[2][1] = 3;
    // D2F.overwrite(A3);
    // D2F.print_graph();
    // D2F.prims();

    // // V = 4, D = 0
    // Complete_Undirected Z = Complete_Undirected(512, 2);
    // Z.generate_graph();
    // Z.print_graph();
    // float t = Z.prims();
    // cout<<t<<'\n';

    // tests for edge reduction
    Complete_Undirected D2 = Complete_Undirected(512, 2);
    Complete_Undirected D3 = Complete_Undirected(512, 3);
    Complete_Undirected D4 = Complete_Undirected(512, 4);

    D2.generate_graph(true);
    D3.generate_graph(true);
    D4.generate_graph(true);

    return 0;
}
