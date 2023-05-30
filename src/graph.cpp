#include "graph.hpp"

using namespace std;

Graph::Graph(int v) {
    this->num_vert = v;
}

Graph Graph::read_info() {

    int vertices, edges;
    cin >> vertices >> edges;

    // INICIALIZA O GRAFO
    Graph graph(vertices);

    // LE TODAS AS ARESTAS
    int v1, v2;
    for (int i = 0; i < edges; i++) {
        cin >> v1 >> v2;
        graph.add_edge(v1, v2);
    }
    graph.sort();

    return graph;
}

void Graph::add_edge(int v1, int v2) {
    graph_map[v1].push_back(v2);
}

void Graph::sort() {
    for (int i = 0; i < num_vert; i++) {
        graph_map[i].sort();    
    }
}

void Graph::DFS(int vertex, vector<bool>& visited, vector<int>& timing, int& cnt) {

    visited[vertex] = true;
 
    for (int prox_v : graph_map[vertex]) {  
        if (prox_v >= 0 && !visited[prox_v]) {
            DFS(prox_v, visited, timing, cnt);
        }
    }

    timing[vertex] = cnt++;
}

Graph Graph::transpose() {
    Graph gt(num_vert);

    for (int i = 0; i < num_vert; i++) {
        for (list<int>::iterator it = graph_map[i].begin(); it != graph_map[i].end(); it++) {
            gt.add_edge(*it, i);
        }
    }

    return gt;
    
}

void Graph::run() {

    vector<bool> visited(num_vert, false);
    vector<int> timing(num_vert, -1);
    int cnt = 0;

    // DFS PARA DETERMINAR O TEMPO DE TERMINO DE CADA VERTICE
    for (int i = 0; i < num_vert; i++) {
        if (!visited[i]) {
            DFS(i, visited, timing, cnt);
        }
    }

    for (int i = 0; i < num_vert; i++)
    {
        cout << timing[i] << endl;
    }
        
    // TRANSPOSIÇÃO DO GRAFO
    Graph gt = transpose();

    // DFS DO VERTICE DE MAIOR TEMPO DE TERMINO
    

    // OS VERTICES QUE 
}
