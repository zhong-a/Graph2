//
//  Graph.cpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//
#include <iostream>
#include <queue>

#include "Graph.hpp"

Graph::Graph(const std::vector<Edge>& edges) {
    numNodes = edges.size();
    city.resize(numNodes);
    for (int i = 0; i < numNodes; i++) {
        city[i].resize(numNodes);
    }
    for (int j = 0; j < numNodes; j++) {
        city[edges[j].source].addDirectedEdge(edges[j]);
        //comment out next line for directed graph
        //city[edges[j].destination].addUndirectedEdge(edges[j]);
    }
    distances.resize(numNodes);
    visited.resize(numNodes);
}

void Graph::clear() {
    distances.resize(numNodes);
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX; // initialize distances to "infinity"
    }
    visited.resize(numNodes);
    for (int j = 0; j < numNodes; j++) {
        visited[j] = false;
    }
}

//djikstraUtil checks all the neighbors of the top element in pq
void Graph::dijkstraUtil(std::priority_queue<pp, std::vector<pp>, Compare>& pq) {
    if (pq.empty()) {
        std::cout << "No path found" << std::endl;
        return;
    }
    pp curr = pq.top();
    pq.pop();
    std::cout << curr.first << ",  " << curr.second << std::endl;
    visited[curr.first] = true;
    //consider the neighbors
    for (int i = 0; i < numNodes; i++) {
        if (city[curr.first].at(i) != 0) {//there is a connection
            std::cout << "Found a path going from " << curr.first << " going to " << i << std::endl;
            int newDist = distances[curr.first] + city[curr.first].at(i);
            if (newDist < distances[curr.first]) {
                distances[curr.first] = newDist;
            }
            curr.second = city[curr.first].at(i);
            curr.first = i;
            pq.push(curr);
        }
    }
    //if (distances[curr.first] < distances[curr.first])
}

int Graph::dijkstra(int startNode, int endNode) {
    clear();
    std::priority_queue<pp, std::vector<pp>, Compare> pq;
    pp curr;
    curr.first = startNode;
    curr.second = 0;
    distances[startNode] = 0;
    visited[startNode] = true;
    pq.push(curr);
    while (!visited[endNode]) {
        dijkstraUtil(pq);
    }
    return distances[endNode];
}
