//
//  Graph.hpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//
#include <queue>
#include <vector>

#include "Graph_util.hpp"

struct Graph {
    size_t numNodes; //number of Nodes
    std::vector<Neighborhood> city;
    std::vector<int> distances;
    std::vector<bool> visited;
    
    Graph(const std::vector<Edge>&);
    //void addEdge(Edge&);
    //BFS() input is the starting vector
    //void bfs();
    //void dfs();
    int dijkstra(int, int);
    void dijkstraUtil(std::priority_queue<pp, std::vector<pp>, Compare>&);
    void clear();
};
