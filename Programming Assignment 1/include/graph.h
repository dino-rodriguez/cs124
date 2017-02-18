/*
 * Header file for graph structure
 *
 * Made by SJ Kim and Dino Rodriguez.
 */


// Class for complete and undirected graphs
class Complete_Undirected {

private:
    int vertices, dimension;

public:
    // constructor, always takes in vertices
    Complete_Undirected(vertices, dimension) {
        std::cout << "Complete_Undirected constructor called." << '\n';
    }
    // destructor, implicitly called and no arguments
    ~Complete_Undirected( void ) {
        std::cout << "Complete_Undirected constructor called." << '\n';
    }

    // methods
    void generate_graph(int, int);
    void print_graph();
}
