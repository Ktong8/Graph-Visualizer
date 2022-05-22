#include "node.hpp"

void Node::setVal(int val) {
    this->val = val;
}

void Node::setX(int x) {
    this->x = x;
}

void Node::setY(int y) {
    this->y = y;
}

void Node::setStatus(Status status) {
    this->status = status;
}

int Node::getX() {
    return this->x;
}

int Node::getY() {
    return this->y;
}

int Node::getVal() {
    return this->val;
}

bool Node::isProcessing() {
    return this->status == Processing;
}

bool Node::isComplete() {
    return this->status == Complete;
}

bool Node::isReached() {
    return this->status != Unreached;
}