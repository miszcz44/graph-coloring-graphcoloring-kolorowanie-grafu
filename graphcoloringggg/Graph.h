#include <iostream>
#include <stdlib.h>

class Graph
{
    int numberOfVertices;    
    int** Edges;    
public:

    Graph(int vertices, int** edges);
    ~Graph();
    int getNumberOfVertices();
    int** getEdges();
    void setNumberOfVertices(int vertices);
    void setEdges(int** edges);
    void greedyColoring(int numberOfVertices, int** adjacencyMatrix);
};
