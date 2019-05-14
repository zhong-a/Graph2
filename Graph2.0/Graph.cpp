//
//  Graph.cpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//
#include <iostream>
#include <queue>
#include <unordered_map>

#include "Graph.hpp"

Graph::Graph(const std::vector<Edge>& edges, int n) {
    numNodes = n;
    city.resize(numNodes);
    for (int i = 0; i < numNodes; i++) {
        city[i].resize(numNodes);
    }
    for (int j = 0; j < edges.size(); j++) {
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
        distances[i] = std::numeric_limits<double>::infinity(); // initialize distances to "infinity"
    }
    visited.resize(numNodes);
    for (int j = 0; j < numNodes; j++) {
        visited[j] = false;
    }
}

//djikstraUtil checks all the neighbors of the top element in pq
void Graph::dijkstraUtil(std::priority_queue<pp, std::vector<pp>, Compare>& pq) {
    if (pq.empty()) {
        return;
    }
    pp curr = pq.top();
    pq.pop();
    //std::cout << curr.first << ",  " << curr.second << std::endl;
    //consider the neighbors
    for (int i = 0; i < numNodes; i++) {
        if (city[curr.first].at(i) != 0) {//there is a connection
            //std::cout << "Found a path going from " << curr.first << " going to " << i << std::endl;
            if (distances[curr.first] == INT_MAX) {
                distances[curr.first] = city[curr.first].at(i);
            }
            else {
                if ((distances[curr.first] + city[curr.first].at(i)) < distances[curr.first]) {
                    distances[curr.first] = distances[curr.first] + city[curr.first].at(i);
                }
            }
            /*if (!visited[curr.first]) {
                newPair.second = city[curr.first].at(i);
                newPair.first = i;
                pq.push(newPair);
            */}
        }
    visited[curr.first] = true;
}


//startNode and endNode using index starting from 1
int Graph::dijkstra(int s, int e) {
    int startNode = s - 1;
    int endNode = e - 1;
    clear();
    std::priority_queue<pp, std::vector<pp>, Compare> pq;
    pp curr;
    curr.first = startNode;
    curr.second = 0;
    distances[startNode] = 0;
    pq.push(curr);
    for (int i = 0; i < numNodes; i++) {
        if (i != startNode) {
            curr.first = i;
            curr.second = INT_MAX;
            pq.push(curr);
        }
    }
    while (!visited[endNode]) {
        dijkstraUtil(pq);
        if (pq.empty()) {
            std::cout << "No path found" << std::endl;
            return 0;
        }
    }
    return distances[endNode];
}

void Graph::printPaths() {
    for (int i = 0; i < numNodes; i++) {
        std::cout << "Node " << i << " connects to ";
        city[i].printNodes();
        std::cout << std::endl;
    }
}

int Graph::dijkstra2(int start, int end) {
    clear();
    int startNode = start - 1;
    int endNode = end - 1;
    std::unordered_map<int, float> map;
    for (int i = 0; i < numNodes; i ++) { //load up the map with all the nodes
        if (i == startNode) {
            continue;
        }
        map[i] = std::numeric_limits<double>::infinity();
    }
    map[startNode] = 0;
    float currentMin = 0;
    int minNode = startNode;
    while (!map.empty()) {
        std::unordered_map<int, float>::iterator it = map.begin();
        currentMin = it->second;
        while (it != map.end()) { //traverse the map look for the smallest element
            if (it->second < currentMin) {
                minNode = it->first;
                currentMin = it->second;
            }
            it ++;
        }
        if (currentMin != std::numeric_limits<double>::infinity()) {
       /* if (map[minNode] == INT_MAX) { // no path
            std::cout << "No Path Found" << std::endl;
            return 0;
        }*/
            std:: cout << "Checking Node " << minNode << std::endl;
            adjustDistances(minNode, map, city[minNode]);
        }
        else {
            std::cout << "No Path Found" << std::endl;
            return 0;
        }
    }
    return map[endNode];
}

void Graph::adjustDistances(int curr, std::unordered_map<int, float>& map, Neighborhood& hood) {
    for (int i = 0; i < hood.numNodes; i++) {
        if (hood.at(i)!= 0) {//path found
            if (map[i] > (map[curr] + city[curr].at(i))) {
                map[i] = map[curr] + city[curr].at(i);
            }
        }
    }
    map.erase(map[curr]);
}

int Graph::dijkstra3(int start, int end) {
    clear();
    int startNode = start - 1;
    int endNode = end - 1;
    std::unordered_map<int, float> map;
    for (int i = 0; i < numNodes; i ++) { //load up the map with all the nodes
        if (i == startNode) {
            continue;
        }
        map[i] = std::numeric_limits<double>::infinity();
    }
    map[startNode] = 0;
    float currentMin = 0;
    int minNode = startNode;
    distances[startNode] = 0;
    while (!visited[endNode] && !map.empty()) {
        currentMin = map.begin()->second;
        minNode = map.begin()->first;
        for (std::unordered_map<int, float>::iterator it = map.begin(); it != map.end(); it++) { //traverse the map look for the smallest element
            if (it->second < currentMin) {
                minNode = it->first;
                currentMin = it->second;
            }
        }
       // if (currentMin != std::numeric_limits<double>::infinity()) {
            /* if (map[minNode] == INT_MAX) { // no path
             std::cout << "No Path Found" << std::endl;
             return 0;
             }*/
            std:: cout << "Checking Node " << minNode << std::endl;
            adjustDistances3(minNode, map, city[minNode]);
        //}
        /*else {
            std::cout << "No Path Found" << std::endl;
            return 0;
        }*/
    }
    return distances[endNode];
}

void Graph::adjustDistances3(int curr, std::unordered_map<int, float>& map, Neighborhood& hood) {
    for (int i = 0; i < hood.numNodes; i++) {
        if (hood.at(i)!= 0) {//path found
            if (visited[i]) {
                if (distances[i] > (distances[curr] + city[curr].at(i))) {
                    distances[i] = distances[curr] + city[curr].at(i);
                }
            }
            else {
                if (map[i] > (distances[curr] + city[curr].at(i))) {
                    map[i] = distances[curr] + city[curr].at(i);
                    distances[i] = distances[curr] + city[curr].at(i);
                }
            }
        }
    }
    map.erase(map.find(curr));
    visited[curr] = true;
}
