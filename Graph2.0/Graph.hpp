//
//  Graph.hpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//
#include <queue>
#include <unordered_map>
#include <vector>

#include "Graph_util.hpp"

struct Graph {
    size_t numNodes; //number of Nodes
    std::vector<Neighborhood> city; //adjacency list of nodes in graph. No path between two nodes is denoted as 0.
    std::vector<float> distances; //keeps track of minimum distances to each node, needs to be reset each dijkstra
    std::vector<bool> visited; //keeps track of visited nodes
    
    Graph(const std::vector<Edge>&, int);
    int dijkstra(int, int);
    void dijkstraUtil(std::priority_queue<pp, std::vector<pp>, Compare>&);
    void clear();
    void printPaths();
    int dijkstra2(int, int);
    void adjustDistances(int, std::unordered_map<int, float>&, Neighborhood&);
    
    int dijkstra3(int, int); //working version of Dijkstra Algorithm
    
    void adjustDistances3(int, std::unordered_map<int, float>&, Neighborhood&);
};

