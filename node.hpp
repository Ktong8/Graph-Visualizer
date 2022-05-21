#ifndef NODE_H_
#define NODE_H_

using namespace std;

class Node {
  private:
    int val;

    // position on screen
    int x;
    int y;

  public:
    Node() : x{0}, y{0}, val{0} {

    };
    Node(int x, int y, int val) : x{x}, y{y}, val{val} {

    };
    
    void setVal(int val);
    void setX(int x);
    void setY(int y);
    int getVal();
    int getX();
    int getY();
};

#endif