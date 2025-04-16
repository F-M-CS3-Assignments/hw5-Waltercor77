#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>  

// BPQNode struct
struct BPQNode {
    int gnode;  
    int pri;      

    //  constructor to initialize values
    BPQNode() : gnode(0), pri(0) {}

    bool operator>(const BPQNode& other) const {
        return pri > other.pri;  
    }

    bool operator==(const BPQNode& other) const {
        return gnode == other.gnode;  
    }
};

class BetterPriorityQueue : public std::priority_queue<BPQNode, std::vector<BPQNode>, std::greater<BPQNode>> {
public:
    //checks if the node is already in the queue
    bool Contains(const BPQNode& node);

    //updates the priority of an existing node
    bool Update(const BPQNode& node);

    // returns a string representation of the queue
    std::string ToString() const;

    //to get string representation of a BPQNode
    static std::string BPQNodeToString(const BPQNode& node);
};

#endif 
