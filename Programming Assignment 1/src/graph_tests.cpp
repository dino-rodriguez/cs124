// libraries
#include "graph.h"
#include <assert.h>

using namespace std;

int main(void) {
    // // generate graphs of each dimension
    // Complete_Undirected D0 = Complete_Undirected(10, 0);
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

    // D1.build_MST();

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
    // Complete_Undirected Z = Complete_Undirected(4, 0);
    // Z.generate_graph();

    // // initialize the 2-D array
    // float** A4 = new float* [4];
    // for(int k = 0; k < 4; k++)
    //     A4[k] = new float[4];
    // A4[0][0] = 0;
    // A4[1][1] = 0;
    // A4[2][2] = 0;
    // A4[3][3] = 0;

    // A4[0][1] = 3;
    // A4[1][0] = 3;
    // A4[0][2] = 5;
    // A4[2][0] = 5;
    // A4[0][3] = 2;
    // A4[3][0] = 2;

    // A4[1][2] = 1;
    // A4[2][1] = 1;
    // A4[1][3] = 1;
    // A4[3][1] = 1;
    // A4[2][3] = 2;
    // A4[3][2] = 2;
    
    // Z.overwrite(A4);
    // Z.print_graph();
    // Z.prims();

    Complete_Undirected mitz_eat_a_dick = Complete_Undirected(32768, 4);
    mitz_eat_a_dick.generate_graph();
    mitz_eat_a_dick.prims();
    return 0;
}
