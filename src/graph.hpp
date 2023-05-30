#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

class Graph {

private:
    int num_vert;
    map<int, list<int>> graph_map;

    
    void DFS(int vertex,  vector<bool>& visited, stack<int>& processed);

    Graph transpose();

public:
    /**
     * @brief construtor da classe Graph
     * 
     * @param v numero de vertices
     */
    Graph(int v);

    static Graph read_info();

    void run();

    /**
     * @brief função para adicionar uma aresta
     * 
     * @param v1 um extremo da aresta
     * @param v2 o outro extremo da aresta
     */
    void add_edge(int v1, int v2);

    /**
     * @brief função para ordenar todas as listas de adjacência dos vertices
     * 
     */
    void sort();
};

#endif