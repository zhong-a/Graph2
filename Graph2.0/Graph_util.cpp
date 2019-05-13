//
//  Graph_util.cpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//

#include <vector>

#include "Graph_util.hpp"

#define pp std::pair<int, int>

Edge::Edge() {
    source = 0;
    destination = 0;
    weight = 0;
}

Edge::Edge(int d, int s, int w) {
    destination = d;
    source = s;
    weight = 0;
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
    nodes[e.destination] = e.weight;
}

void Neighborhood::addUndirectedEdge(const Edge& e) {
    nodes[e.source] = e.weight;
}

int Neighborhood::at(int index) {
    return nodes[index];
}
