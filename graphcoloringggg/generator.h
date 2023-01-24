#include <iostream>
#include <stdlib.h>
#include "UserControl.h"
#include <vector>
#pragma once

using std::string;

class Generator : public UserControl {

    int** Edges;
    int** AdjacencyMatrix;

public:
    //Generator(int vertices, int edges);
    Generator();
    ~Generator();
    int getNumberOfEdges(UserControl user);
    int getNumberOfVertices(UserControl user);
    int** getEdges();
    void setEdges(int** edges);
    int** generateMatrix(int numberOfEdges);
    int** generateEdges(UserControl user);
    int** generateAdjacencyMatrix(int** edges, UserControl user);

};
