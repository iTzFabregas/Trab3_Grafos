#include <fstream>
#include "../src/graph.hpp"

using namespace std;

int main(void) {

    Graph graph = Graph::read_info();
    graph.run();
}   