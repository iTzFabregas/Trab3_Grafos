#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph {

private:
    int num_vert;
    map<int, list<int>> graph_map;

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
    
    /**
     * @brief função para fazer o BFS no grafo
     * 
     * @param vertex vertice atual do BFS
     * @param visited vector para saber se o vertice foi visitado ou nao
     * @param processed pilha com todos vertices achados pelo BFS 
     */
    void DFS(int vertex,  vector<bool>& visited, stack<int>& processed);

    /**
     * @brief função que cria um grafo transposto do grafo atual
     * 
     * @return Graph grafo transposto
     */
    Graph transpose();

public:
    /**
     * @brief construtor da classe Graph
     * 
     * @param v numero de vertices
     */
    Graph(int v);

    /**
     * @brief função para pegar todos os inputs e criar o grafo
     * 
     * @return Graph grafo gerado
     */
    static Graph read_info();

    /**
     * @brief função que roda o programa pedido no trabalho 3
     * 
     */
    void run();
    
};

#endif