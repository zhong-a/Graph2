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
    Graph g1(edges, 4);
    //g1.printPaths();
    std::cout << "Shortest path in Graph 1 from node 1 to node 4: " << std:: endl;
    std::cout << g1.dijkstra3(1, 4) << std::endl;
    std::vector<Edge> edges2;
    edges.push_back(Edge(1, 2, 1));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(3, 5, 4));
    edges.push_back(Edge(5, 6, 3));
    edges.push_back(Edge(1, 4, 2));
    edges.push_back(Edge(2, 4, 2));
    edges.push_back(Edge(3, 4, 1));
    edges.push_back(Edge(4, 5, 2));
    edges.push_back(Edge(7, 4, 1));
    Graph g2(edges, 7);
    std::cout << "Shortest path in Graph 2 from node 1 to node 6: " << std::endl;
    std::cout << g2.dijkstra3(1, 6) << std::endl;
    return 0;
}
