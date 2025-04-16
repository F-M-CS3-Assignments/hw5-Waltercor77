#include "Dijkstra.h"
#include "BetterPriorityQueue.h"
#include <unordered_map>
#include <climits>

int dijkstra(nodekey_t start, nodekey_t end, const Graph* g) {
    std::unordered_map<nodekey_t, int> distances;

    for (nodekey_t node : g->GetNodes()) {
        distances[node] = INT_MAX;
    }

    distances[start] = 0;

    BetterPriorityQueue pq;
    pq.push(BPQNode{start, 0}); 

    while (!pq.empty()) {
        BPQNode current = pq.top();  
        pq.pop();                    

        nodekey_t currentNode = current.gnode;  


        if (currentNode == end) {
            return distances[end];
        }

        for (nodekey_t neighbor : g->GetNeighbors(currentNode)) {
            int edgeWeight = g->GetWeight(currentNode, neighbor);
            int newDist = distances[currentNode] + edgeWeight;

            if (newDist < distances[neighbor]) {
                distances[neighbor] = newDist;
                pq.update(BPQNode{neighbor, newDist});
            }
        }
    }

    return -1; // no path found
}
