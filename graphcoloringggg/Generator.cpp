#include <iostream>
#include <stdlib.h>
#include "generator.h"

using namespace std;

Generator::Generator(int vertices, int edges) {
    numberOfVertices = vertices;
    numberOfEdges = edges;
}

Generator::~Generator() {

}

void Generator::setNumberOfEdges(int edges) {
    numberOfEdges = edges;
}

void Generator::setNumberOfVertices(int vertices) {
    numberOfVertices = vertices;
}

void Generator::setEdges(int** edges) {
    Edges = edges;
}

int Generator::getNumberOfEdges() {
    return numberOfEdges;
}

int Generator::getNumberOfVertices() {
    return numberOfVertices;
}

int** Generator::getEdges() {
    return Edges;
}

int** Generator::generateEdges(int numberOfVertices, int numberOfEdges) {
    int** edge = new int* [numberOfEdges];
    for (int i = 0; i < numberOfEdges; i++) {
        edge[i] = new int[2];
    }
    //Assign random values to the number of vertex and edges of the graph, Using rand().
    int i = 0, j = 0;
    while (i < numberOfEdges)
    {
        edge[i][0] = rand() % numberOfVertices + 1;
        edge[i][1] = rand() % numberOfVertices + 1;
        //Print the connections of each vertex, irrespective of the direction.
        if (edge[i][0] == edge[i][1])
            continue;
        else
        {
            for (j = 0; j < i; j++)
            {
                if ((edge[i][0] == edge[j][0] &&
                    edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] &&
                        edge[i][1] == edge[j][0]))
                    i--;
            }
        } 
        i++;
    }

    /*for (int i = 0; i < numberOfEdges; i++) {
        cout << edge[i][0] << edge[i][1] << endl;
    }*/
    return edge;
}

int** Generator::generateAdjacencyMatrix(int numberOfVertices, int** edges) {
    int** adjacencyMatrix = new int* [numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) {
        adjacencyMatrix[i] = new int[numberOfVertices];
    }
    /*for (int i = 0; i < numberOfEdges; i++) {
        cout << edges[i][0] << edges[i][1] << endl;
    }*/
    for (int i = 0; i < numberOfVertices; i++) {
        for (int j = 0; j < numberOfVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < numberOfEdges; i++) {
        int vertice1 = edges[i][0] - 1;
        int vertice2 = edges[i][1] - 1;
        adjacencyMatrix[vertice1][vertice2] = 1;
        adjacencyMatrix[vertice2][vertice1] = 1;
    }
    /*for (int i = 0; i < numberOfVertices; i++) {
        for (int j = 0; j < numberOfVertices; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }*/
    return adjacencyMatrix;
}
