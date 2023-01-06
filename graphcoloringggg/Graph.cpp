#include <iostream>
#include <stdlib.h>
#include "Graph.h"
#include <algorithm> 
#include <string> 


using namespace std;

Graph::Graph(int vertices) {
	numberOfVertices = vertices;
}

Graph::Graph() {

}

Graph::~Graph() {

}

int Graph::getNumberOfVertices() {
    return numberOfVertices;
}

int** Graph::getEdges() {
    return Edges;
}

void Graph::setNumberOfVertices(int vertices) {
    numberOfVertices = vertices;
}

void Graph::setEdges(int** edges) {
    Edges = edges;
}

void Graph::greedyColoring(int numberOfVertices, int** adjacencyMatrix)
{
    int* color = new int[numberOfVertices];
    color[0] = 0;
    for (int i = 1; i < numberOfVertices; i++) {
        color[i] = -1;
    }

    bool* unused = new bool[numberOfVertices];

    for (int i = 0; i < numberOfVertices; i++) {
        unused[i] = false;
    }


    for (int u = 1; u < numberOfVertices; u++) {    //for all other NODE - 1 vertices
        for (int v = 0; v < numberOfVertices; v++) {
            if (adjacencyMatrix[u][v]) {
                if (color[v] != -1)    //when one color is assigned, make it unavailable
                    unused[color[v]] = true;
            }
        }

        int col;
        for (col = 0; col < numberOfVertices; col++) {
            if (!unused[col])    //find a color which is not assigned
                break;
        }

        color[u] = col;    //assign found color in the list

        for (int v = 0; v < numberOfVertices; v++) {    //for next iteration make color availability to false
            if (adjacencyMatrix[u][v]) {
                if (color[v] != -1)
                    unused[color[v]] = false;
            }
        }
    }
    int maxColor = 0;
    for (int u = 0; u < numberOfVertices; u++) {
        cout << "Wierzcho³ek: " << u+1 << ", Kolor: " << color[u] << endl;
        if (color[u] > maxColor) {
            maxColor = color[u];
        }
    }
    cout << "Liczba kolorów algorytmem zach³annym: " + to_string(maxColor + 1) << endl;
    
}



