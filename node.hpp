#ifndef NODE_H_
#define NODE_H_

/**
 * @brief A Status enum to represent the status of each node, either
 * completed, processing, or unreached
 * 
 */
enum Status {Complete, Processing, Unreached};

/**
 * @brief A Node class to represent a node in the graph, along with
 * the details for rendering (position)
 * 
 */
class Node {
  private:
    int val;
    Status status;
    // position on screen
    int x;
    int y;

  public:
    Node() : x{0}, y{0}, val{0}, status{Complete} {

    };
    Node(int x, int y, int val) : x{x}, y{y}, val{val}, status{Complete} {

    };
    
    /**
     * @brief Set the value at this node
     * 
     * @param val the value to set the node to
     */
    void setVal(int val);

    /**
     * @brief Set the x-value of this node
     * 
     * @param x the x position to move the node to
     */
    void setX(int x);

    /**
     * @brief Set the y-value of this node
     * 
     * @param y the y position to move the node to
     */
    void setY(int y);

    /**
     * @brief Get the Val at this node
     * 
     * @return the value at this node
     */
    int getVal();

    /**
     * @brief Get the x-coordinate of this node
     * 
     * @return the x-coordinate of this node
     */
    int getX();

    /**
     * @brief Get the y-coordinate of this node
     * 
     * @return the y-coordinate of this node
     */
    int getY();

    /**
     * @brief Determine wheter or not the node is being processed
     * 
     * @return true The node is currently being processed
     * @return false The node is not currently being processed
     */
    bool isProcessing();

    /**
     * @brief Determine whether or not the node has completed processing
     * 
     * @return true The node has completed processing
     * @return false The node has not completed processing
     */
    bool isComplete();

    /**
     * @brief Determine whether or not the node has been reached
     * 
     * @return true The node has been reached
     * @return false The node has not been reached
     */
    bool isReached();
};

#endif