#include <iostream>
#include <stdlib.h>
#include <vector>
#pragma once

using namespace std;

class Graph
{
    int** Edges;
protected:
    int numberOfVertices;    
public:

    Graph(int vertices);
    Graph();
    ~Graph();
    int getNumberOfVertices();
    int** getEdges();
    void setNumberOfVertices(int vertices);
    void setEdges(int** edges);
    void greedyColoring(int numberOfVertices, int** adjacencyMatrix);
};

