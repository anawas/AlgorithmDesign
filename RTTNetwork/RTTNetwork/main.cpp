//
//  main.cpp
//  RTTNetwork
//
//  Created by Andreas Wassmer on 21.12.16.
//  Copyright © 2016 Andreas Wassmer. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;  // number of vertices
    list<int> *adj; // Pointer to array containing adjacency list

public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}


int main(int argc, const char * argv[]) {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 5);
    
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 7);
    
    g.addEdge(3, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    
    g.addEdge(5, 0);
    g.addEdge(5, 3);
    g.addEdge(5, 6);
    
    g.addEdge(6, 4);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    
    g.addEdge(7, 2);
    g.addEdge(7, 4);
    g.addEdge(7, 6);
}
