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

/**
 * @brief A Graph class, representing a directed or undirected simple graph. 
 * 
 */
class Graph {
  private:

    // the set of nodes in the graph stored to allow indices
    vector<Node> m_nodes;

    // an adjacency list dealing
    vector<unordered_map<int, int>> m_adjacency_list;

    // a set of edges in the graph for easy access during rendering
    unordered_set<pair<int, int>, pair_hash> m_edges;

    // the number of nodes currently in the graph
    int size;
  public:
    Graph() : size{0} {

    }

    // modifiers
    /**
     * @brief Adds a Node into the graph
     * 
     * @param node the node being added into the graph
     */
    void addNode(Node node);

    /**
     * @brief Adds a directed edge into the graph
     * 
     * @param u the source node of the edge
     * @param v the destination node of the edge
     * @param weight the weight of this directed edge
     */
    void addDirectedEdge(int u, int v, int weight);

    /**
     * @brief Adds an undirected edge into the graph
     * 
     * @param u one node of the edge
     * @param v the other node of the edge
     * @param weight the weight of this undirected edge
     */
    void addUndirectedEdge(int u, int v, int weight);

    /**
     * @brief Removes the undirected edge connecting u and v from the graph
     * 
     * @param u one node of the edge
     * @param v the other node of the edge
     */
    void removeUndirectedEdge(int u, int v);

    /**
     * @brief Removes the directed edge from u to v from the graph
     * 
     * @param u the source node of the edge
     * @param v the destination node of the edge
     */
    void removeDirectedEdge(int u, int v);

    /**
     * @brief Removes a node from the graph
     * 
     * @param n the index of the node in the nodes array
     */
    void removeNode(int n);

    // getters
    /**
     * @brief Get the Node at index n
     * 
     * @param n the index of the desired node
     * @return The Node at the given index n 
     */
    Node getNode(int n);

    /**
     * @brief Get the Nodes vector
     * 
     * @return the vector of nodes in the graph
     */
    vector<Node> getNodes();

    /**
     * @brief Get the edges set of the graph
     * 
     * @return the set of edges in the graph 
     */
    unordered_set<pair<int, int>, pair_hash> getEdges();

    // unweighted
    /**
     * @brief Performs breadth-first search in the graph starting at the 
     * node at the passed in source index
     * 
     * @param source the index of the source node
     */
    void bfs(int source);

    /**
     * @brief Performs depth-first search in the graph starting at the
     * node at the passed in source index
     * 
     * @param source the index of the source node
     */
    void dfs(int source);

    /**
     * @brief Obtains the topological sort of the graph
     * 
     * @return A vectors of ints representing the topological order of
     * the nodes in the graph
     */
    vector<int> topologicalSort();

    /**
     * @brief Performs Tarjan's Algorithm to obtain the strongly connected
     * components of the graph
     * 
     */
    void tarjans();

    /**
     * @brief Performs Kosaraju's Algorithm to obtain the strongly 
     * connected components of the graph
     * 
     */
    void kosarajus();

    // single source shortest path

    /**
     * @brief Performs Dijkstra's Algorithm on the graph starting at the
     * given source node
     * 
     * @param source the index of the source node
     */
    void dijkstras(int source);

    /**
     * @brief Performs Bellman-Ford's Algorithm on the graph starting at
     * the given source node
     * 
     * @param source the index of the source node
     */
    void bellmanFord(int source);

    // minimum spanning trees

    /**
     * @brief Performs Prim's Algorithm on the graph to find a minimum
     * spanning tree
     * 
     */
    void prims();

    /**
     * @brief Performs Kruskall's Algorithm on the graph to find a 
     * minimum spanning tree
     * 
     */
    void kruskalls();

    // all pair shortest path
    /**
     * @brief Performs Johnson's Algorithm to find the shortest path
     * between all pairs of nodes in the graph
     * 
     */
    void johnsons();

    /**
     * @brief Performs Floyd-Warshall's Algorithm to find the shortest
     * path between all pairs of nodes in the graph
     * 
     */
    void floydWarshalls();
};

#endif