#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef int VERTEX;

class Graph {

private:
    int num_vert;
    map<VERTEX, list<VERTEX>> graph_map;

    
    void DFS(VERTEX vertex,  vector<bool>& visited, queue<VERTEX>& timing);

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
    void add_edge(VERTEX v1, VERTEX v2);

    /**
     * @brief função para ordenar todas as listas de adjacência dos vertices
     * 
     */
    void sort();
};

#endif