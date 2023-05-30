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

void Graph::DFS(int vertex, vector<bool>& visited, stack<int>& processed) {

    visited[vertex] = true;
 
    for (int prox_v : graph_map[vertex]) {  
        if (prox_v >= 0 && !visited[prox_v]) {
            DFS(prox_v, visited, processed);
        }
    }

    processed.push(vertex);
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
    stack<int> processed;

    // DFS PARA DETERMINAR O TEMPO DE TERMINO DE CADA VERTICE
    for (int i = 0; i < num_vert; i++) {
        if (!visited[i]) {
            DFS(i, visited, processed);
        }
    }
        
    // TRANSPOSIÇÃO DO GRAFO
    Graph gt = transpose();

    // DFS DO VERTICE DE MAIOR TEMPO DE TERMINO
    vector<bool> visitedTrans(num_vert, false);
    stack<int> curr;
    list<list<int>> elements;
    int cnt = 0;

    while (!processed.empty()) {
        if (!visitedTrans[processed.top()]) {

            gt.DFS(processed.top(), visitedTrans, curr);

            list<int> buffer;
            while(!curr.empty()) {
                buffer.push_back(curr.top());
                curr.pop();
            }
            buffer.sort();
            elements.push_back(buffer);
            buffer.clear();
            cnt++;
        }
        processed.pop();
    }
    elements.sort();

    cout << cnt << endl;
    for (list<list<int>>::iterator it = elements.begin(); it != elements.end(); it++) {
        for (list<int>::iterator jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << " ";
        }
        cout << endl;
    }
    
}
