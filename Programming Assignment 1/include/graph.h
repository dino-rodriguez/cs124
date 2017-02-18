/*
 * Header file for graph structure.
 *
 * Made by SJ Kim and Dino Rodriguez.
 */


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
    void generate_graph();
    void get_vertices();
    void get_dimension();
    void print_graph();
}
