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
    std::vector<Neighborhood> city;
    std::vector<float> distances;
    std::vector<bool> visited;
    std::vector<int> foundPaths;
    
    Graph(const std::vector<Edge>&, int);
    //void addEdge(Edge&);
    //BFS() input is the starting vector
    //void bfs();
    //void dfs();
    int dijkstra(int, int);
    void dijkstraUtil(std::priority_queue<pp, std::vector<pp>, Compare>&);
    void clear();
    void printPaths();
    int dijkstra2(int, int);
    void adjustDistances(int, std::unordered_map<int, float>&, Neighborhood&);
    
    int dijkstra3(int, int);
    void adjustDistances3(int, std::unordered_map<int, float>&, Neighborhood&);
};

