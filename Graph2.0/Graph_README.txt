A graph is a collection of nodes and their associated paths. Nodes are uniquely identifiable- node u, node v- while paths are denoted path(u,v) for any node u and v and have an associated static weight(u,v). If there is path(u,v) then v is adjacent to u. 


Dijkstra’s Algorithm finds the minimal route distance between a source node s to a destination node d. A route between two nodes is composed of at least one path. If there is no route from s to d, the algorithm should en[a]d.


Dijkstra’s algorithm uses three auxiliary containers. Dist should contain the distances from the source node s to all other nodes z; if there are n nodes in graph, Dist should contain n values. Because nodes have no inherent weight, Dist(s) is initialized to 0 while Dist(z) of all other nodes z is initialized to infinity. 


Q initially contains all nodes in the graph. A node u is taken out of Q after all adjacent nodes to u are considered. When there is no path from source node s to destination d, unreachable nodes should remain in Q after the algorithm ends. 


S is initially an empty set and indicates which nodes the algorithm has visited. When the destination node has been added to S, the algorithm ends, because the minimum distance from source to destination has been found. Nodes that are unreachable from the source will not ever be added to S. S helps prevent cycles, because a node u whose adjacent nodes have already been analyzed should never be analyzed again.


Algorithm steps: 
Initialization: dist(s) is initialized to 0 while dist of all other nodes is initialized to infinity. Q contains all the nodes in the graph - check that source s and destination d exist in Q, otherwise break. Check also if s == d, in which case return 0. Initialize S to be empty. 
1. While Q is not empty, select node u with the smallest Dist(u), that is not already in S, from Q. If Dist(u) is infinity, then there is no minimum path from source s to destination d. 
2. Update Dist values of adjacent nodes of the current node u as follows: For each adjacent node v
   1. If Dist(u) + weight(u,v) < dist(v), there is a new min distance found for node v; update dist(v) to Dist(u) + weight(u,v). 
   2. Else No updates are made to Dist(v)


1. Add node u to S, to indicate that u has been visited. If node u == destination d, return Dist(u).
2. Go back to step 1.


[a]example