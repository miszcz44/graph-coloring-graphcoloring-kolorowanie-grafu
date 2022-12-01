#include <iostream>
#include <stdlib.h>

using std::string;

class Generator {

    int numberOfVertices;
    int numberOfEdges;
    int** Edges;
    int** AdjacencyMatrix;

public:
    Generator(int vertices, int edges);
    ~Generator();
    void setNumberOfVertices(int vertices);
    void setNumberOfEdges(int edges);
    int getNumberOfEdges();
    int getNumberOfVertices();
    int** getEdges();
    void setEdges(int** edges);
    int** generateEdges(int edges, int vertices);
    int** generateAdjacencyMatrix(int vertices, int** edges);

};
