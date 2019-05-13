//
//  main.cpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//
#include <iostream>
#include <vector>

#include "Graph.hpp"

int main() {
    std::vector<Edge> edges;
    edges.push_back(Edge(1, 2, 1));
    edges.push_back(Edge(2, 3, 2));
    edges.push_back(Edge(3, 4, 3));
    edges.push_back(Edge(4, 1, 4));
    edges.push_back(Edge(1, 3, 5));
    edges.push_back(Edge(3, 1, 6));
    Graph g1(edges);
    std::cout << "Shortest path from node 1 to node 4: " << g1.dijkstra(1, 4) << std::endl;
    return 0;
}
