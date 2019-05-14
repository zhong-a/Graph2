//
//  Graph_util.cpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//
#include <iostream>
#include <vector>

#include "Graph_util.hpp"

#define pp std::pair<int, int>

Edge::Edge() {
    source = 0;
    destination = 0;
    weight = 0;
}

Edge::Edge(int s, int d, float w) {
    destination = d - 1;
    source = s - 1;
    weight = w;
}

bool Compare::operator()(pp first, pp second) {
    return (first.second > second.second);
}

Neighborhood::Neighborhood() {
    numNodes = 0;
    std::vector<int> nodes;
}

void Neighborhood::resize(int size) {
    numNodes = size;
    nodes.resize(numNodes);
}

void Neighborhood::addDirectedEdge(const Edge& e) {
    //std::cout << e.source << " " << e.destination << " " << e.weight << std::endl;
    nodes[e.destination] = e.weight;
}

void Neighborhood::addUndirectedEdge(const Edge& e) {
    nodes[e.source] = e.weight;
}

int Neighborhood::at(int index) {
    return nodes[index];
}

void Neighborhood::printNodes() {
    for (int i = 0; i < numNodes; i++){
        if (nodes[i]!= 0) {
            std::cout << i << std::endl;
        }
    }
}

bool Neighborhood::isPath(int dest) {
    if (nodes[dest] == 0) {
        return false;
    }
    return true;
}
