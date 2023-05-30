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

void Graph::add_edge(VERTEX v1, VERTEX v2) {
    graph_map[v1].push_back(v2);
}

void Graph::sort() {
    for (int i = 0; i < num_vert; i++) {
        graph_map[i].sort();    
    }
}

void Graph::DFS(VERTEX vertex, vector<bool>& visited, queue<VERTEX>& timing) {

    visited[vertex] = true;
 
    for (int prox_v : graph_map[vertex]) {  
        if (prox_v >= 0 && !visited[prox_v]) {
            DFS(prox_v, visited, timing);
        }
    }

    timing.push(vertex);
}

void Graph::run() {

    vector<bool> visited(num_vert, false);
    queue<VERTEX> timing;
    DFS(0, visited, timing);
    cout << "oi" << endl;

    while(!timing.empty())
    {
        cout << timing.front() << " ";
        timing.pop();
    }
    
    // DFS PARA DETERMINAR O TEMPO DE TERMINO DE CADA VERTICE

    // TRANSPOSIÇÃO DO GRAFO

    // DFS DO VERTICE DE MAIOR TEMPO DE TERMINO

    // OS VERTICES QUE 
}
