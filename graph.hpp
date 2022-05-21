#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "node.hpp"

using namespace std;

struct pair_hash {
  inline size_t operator()(const pair<int, int>& edge) const {
    return 100 * edge.first + edge.second;
  }
};

class Graph {
  private:
    vector<Node> m_nodes;
    vector<unordered_map<int, int>> m_adjacency_list;
    unordered_set<pair<int, int>, pair_hash> m_edges;
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
    vector<Node> getNodes();
    unordered_set<pair<int, int>, pair_hash> getEdges();

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