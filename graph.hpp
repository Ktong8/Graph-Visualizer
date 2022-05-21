#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<unordered_set>
#include "node.hpp"

using namespace std;

class Graph {
  private:
    vector<Node> m_nodes;
    vector<unordered_set<int>> m_adjacency_list;
    vector<vector<int>> m_adjacency_matrix;
  public:
    Graph();

    // modifiers
    void addNode();
    void addEdge(int u, int v, int weight);
    void removeEdge(int u, int v);
    void removeNode(int n);

    // getters
    Node getNode(int n);

    // unweighted
    void bfs(int source);
    void dfs(int source);
    void topologicalSort();
    void tarjans();
    void kosarajus();

    // single source shortest path
    void dijkstras(int source);
    void bellmanFord(int source);

    // minimum spanning trees
    void prims();
    void kruskalls();

    // all pair shortest path
    void johnsons();
    void floydWarshalls();
};

#endif