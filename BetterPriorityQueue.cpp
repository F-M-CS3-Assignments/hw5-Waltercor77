#include "BetterPriorityQueue.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

// Method to check if a BPQNode exists in the priority queue
bool BetterPriorityQueue::Contains(const BPQNode& node) {

    if (this->c.empty()) {
        return false;
    }

    // Loop through all elements in the queue for any mathchesd
    for (size_t i = 0; i < this->c.size(); i++) {
        const BPQNode& n = this->c[i];
        if (n.gnode == node.gnode) {
            return true;
        }
    }

    return false;
}





// Method to update the priority of a BPQNode
bool BetterPriorityQueue::Update(const BPQNode& node) {

    for (size_t i = 0; i < this->c.size(); ++i) {

        if (this->c[i].gnode == node.gnode) {

            this->c[i].pri = node.pri;
            
            std::make_heap(this->c.begin(), this->c.end(), std::greater<BPQNode>());
            
            return true;
        }
    }

    // false if the node is not found
    return false;
}



// string representation of the pri queue
std::string BetterPriorityQueue::ToString() const {
    std::string result = "[";
    for (size_t i = 0; i < this->c.size(); ++i) {
        result += BPQNodeToString(this->c[i]);
        if (i != this->c.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}

//  string representation of a single BPQNode
std::string BetterPriorityQueue::BPQNodeToString(const BPQNode& node) {
    return "(" + std::to_string(node.gnode) + ", pri: " + std::to_string(node.pri) + ")";
}
