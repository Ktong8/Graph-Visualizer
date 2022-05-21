#include "graph.hpp"

void Graph::addNode(Node node) {
    m_nodes.push_back(node);
    unordered_map<int, int> temp;
    m_adjacency_list.push_back(temp);
    size++;
}

void Graph::addDirectedEdge(int u, int v, int weight) {
    m_adjacency_list[u][v] = weight;
    m_edges.insert({u, v});
}

void Graph::addUndirectedEdge(int u, int v, int weight) {
    m_adjacency_list[u][v] = weight;
    m_adjacency_list[v][u] = weight;
    m_edges.insert({u, v});
    m_edges.insert({v, u});
}

void Graph::removeDirectedEdge(int u, int v) {
    m_adjacency_list[u].erase(v);
    m_edges.erase({u, v});
}

void Graph::removeUndirectedEdge(int u, int v) {
    m_adjacency_list[u].erase(v);
    m_adjacency_list[v].erase(u);
    m_edges.erase({u, v});
    m_edges.erase({v, u});
}

void Graph::removeNode(int n) {
    m_nodes.erase(m_nodes.begin() + n);
    for (const auto & [next, _] : m_adjacency_list[n]) {
        m_edges.erase({n, next});
    }
    m_adjacency_list.erase(m_adjacency_list.begin() + n);
    size--;
    for (int i = 0; i < size; ++i) {
        if (m_adjacency_list[i].find(n) != m_adjacency_list[i].end()) {
            m_adjacency_list[i].erase(n);
            m_edges.erase({i, n});
        }
    }
}

Node Graph::getNode(int n) {
    return m_nodes[n];
}

vector<Node> Graph::getNodes() {
    return m_nodes;
}

unordered_set<pair<int, int>, pair_hash> Graph::getEdges() {
    return m_edges;
}

void Graph::bfs(int source) {

}

void Graph::dfs(int source) {

}

vector<int> Graph::topologicalSort() {

}

void Graph::tarjans() {

}

void Graph:: kosarajus() {

}

void Graph::dijkstras(int source) {

}

void Graph::bellmanFord(int source) {

}

void Graph::prims() {

}

void Graph::kruskalls() {

}

void Graph::johnsons() {

}

void Graph::floydWarshalls() {

}