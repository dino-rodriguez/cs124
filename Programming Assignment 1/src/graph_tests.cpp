// libraries
#include "graph.h"
#include <assert.h>

using namespace std;

int main(void) {
    // generate graphs of each dimension
    Complete_Undirected D0 = Complete_Undirected(10, 0);
    Complete_Undirected D1 = Complete_Undirected(10, 1);
    Complete_Undirected D2 = Complete_Undirected(10, 2);
    Complete_Undirected D3 = Complete_Undirected(10, 3);
    Complete_Undirected D4 = Complete_Undirected(10, 4);

    // get vertice numbers
    assert(D0.get_vertices() == 10);
    assert(D4.get_vertices() == 10);

    // get dimension
    assert(D0.get_dimension() == 0);
    assert(D4.get_dimension() == 4);

    // get graph, print location in memory
    assert(D0.generate_graph() == D0.get_graph());

    // print some graphs
    D1.generate_graph();
    D4.generate_graph();

    cout<<"D0\n";
    D0.print_graph();
    cout<<"D1\n";
    D1.print_graph();
    cout<<"D2\n";
    D2.print_graph();
    cout<<"D4\n";
    D4.print_graph();

    // test prims on simple examples
    D0.simple_graph(D1.get_graph());

    return 0;
}
