#include "graph.hpp"

void Graph::addNode(Node node) {
    m_nodes.push_back(node);
    unordered_map<int, int> temp;
    m_adjacency_list.push_back(temp);
    m_size++;
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
    m_size--;
    for (int i = 0; i < m_size; ++i) {
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

void Graph::resetNodes() {
    for (int i = 0; i < m_size; ++i) {
        m_nodes[i].setStatus(Unreached);
    }
}

void Graph::bfs(int source) {
    resetNodes();
    queue<int> nodes_queue;
    nodes_queue.push(source);
    while(!nodes_queue.empty()) {
        int current = nodes_queue.front();
        nodes_queue.pop();
        m_nodes[current].setStatus(Processing);
        for (const auto &[next, _] : m_adjacency_list[current]) {
            if (!m_nodes[next].isReached()) {
                nodes_queue.push(next);
                m_nodes[next].setStatus(Pending);
            }
        }
        m_nodes[current].setStatus(Complete);
    }
}

void Graph::dfs(int source) {
    resetNodes();
    stack<int> nodes_stack;
    nodes_stack.push(source);
    while (!nodes_stack.empty()) {
        int current = nodes_stack.top();
        nodes_stack.pop();

        if (!m_nodes[current].isReached()) {
            m_nodes[current].setStatus(Processing);
        }

        for (const auto &[next, _] : m_adjacency_list[current]) {
            if (!m_nodes[next].isReached()) {
                nodes_stack.push(next);
            }
        }
        m_nodes[current].setStatus(Complete);
    }
}

vector<int> Graph::topologicalSort() {
    return vector<int>(0);
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