#include <iostream>
#include "../include/graph.h"

/* constructs an adjacency list by connecting nodes based on colocalization and temporal relationships defined by the graph's edges */
void buildAdjacency(const Graph& g, std::unordered_map<Node, std::unordered_set<Node>>& adj) {
    std::unordered_map<int, std::vector<Node>> nodesById;

    // group all nodes by their id    
    for (const Node& node : g.nodes) {
        nodesById[node.id].push_back(node);
    }
    // For each edge, mark the two nodes as neighbors
    for (const Edge& edge : g.edges) {
        const Node& src = edge.source;
        const Node& tgt = edge.target;

        adj[src].insert(tgt);
        adj[tgt].insert(src);
    }
    // Connect same node across different timepoints
    // for (const auto& [id, nodeGroup] : nodesById) {
    //     for (size_t i = 0; i < nodeGroup.size(); ++i) {
    //         for (size_t j = i + 1; j < nodeGroup.size(); ++j) {
    //             const Node& nodeA = nodeGroup[i];
    //             const Node& nodeB = nodeGroup[j];
    //             if (nodeA.timepoint != nodeB.timepoint) {
    //                 adj[nodeA].insert(nodeB);
    //                 adj[nodeB].insert(nodeA);
    //             }
    //         }
    //     }
    // }
}
