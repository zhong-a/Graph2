//
//  Graph_util.hpp
//  Graph2.0
//
//  Created by Alan Zhong on 5/11/19.
//  Copyright © 2019 Alan Zhong. All rights reserved.
//

#include <vector>

#define pp std::pair<int, int>

struct Edge {
    int destination;
    int source;
    int weight;
    
    Edge();
    Edge(int, int, int);
};

struct Neighborhood {
    size_t numNodes;
    std::vector<int> nodes;
    
    Neighborhood();
    //takes in int for numNodes
    void resize(int);
    void addDirectedEdge(const Edge&);
    void addUndirectedEdge(const Edge&);
    //returns weight of path to destination
    int at(int);
};

class Compare {
public:
    bool operator() (pp, pp);
};
