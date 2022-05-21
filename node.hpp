#ifndef NODE_H_
#define NODE_H_

using namespace std;

enum Status {Complete, Processing};

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
    
    void setVal(int val);
    void setX(int x);
    void setY(int y);
    int getVal();
    int getX();
    int getY();
    bool isProcessing();
};

#endif