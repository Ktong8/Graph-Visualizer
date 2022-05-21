#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<unordered_map>
#include "node.hpp"

using namespace std;

class Graph {
  private:
    vector<Node> m_nodes;
    vector<unordered_map<int, int>> m_adjacency_list;
    int size;
  public:
    Graph() : size{0} {
      
    }

    // modifiers
    void addNode(Node node);
    void addDirectedEdge(int u, int v, int weight);
    void addUndirectedEdge(int u, int v, int weight);
    void removeUndirectedEdge(int u, int v);
    void removeDirectedEdge(int u, int v);
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