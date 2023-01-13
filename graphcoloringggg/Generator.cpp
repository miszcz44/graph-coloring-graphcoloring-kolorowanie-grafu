#include <iostream>
#include <stdlib.h>
#include "generator.h"

using namespace std;


Generator::Generator() {

}

Generator::~Generator() {

}

int Generator::getNumberOfEdges(UserControl user) {
    return user.numberOfEdges;
}

int Generator::getNumberOfVertices(UserControl user) {
    return user.numberOfVertices;
}


void Generator::setEdges(int** edges) {
    Edges = edges;
}


int** Generator::getEdges() {
    return Edges;
}

int** Generator::generateMatrix(int numberOfEdges) {
    int** edge = new int* [numberOfEdges];
    for (int i = 0; i < numberOfEdges; i++) {
        edge[i] = new int[2];
    }
    return edge;
}

int** Generator::generateEdges(UserControl user) {
    int** edge = generateMatrix(getNumberOfEdges(user));
    //Assign random values to the number of vertex and edges of the graph, Using rand().
    int i = 0, j = 0;
    while (i < getNumberOfEdges(user))
    {
        edge[i][0] = rand() % getNumberOfVertices(user) + 1;
        edge[i][1] = rand() % getNumberOfVertices(user) + 1;
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

int** Generator::generateAdjacencyMatrix(int** edges, UserControl user) {
    int** adjacencyMatrix = new int* [getNumberOfVertices(user)];
    for (int i = 0; i < getNumberOfVertices(user); i++) {
        adjacencyMatrix[i] = new int[getNumberOfVertices(user)];
    }
    /*for (int i = 0; i < numberOfEdges; i++) {
        cout << edges[i][0] << edges[i][1] << endl;
    }*/
    for (int i = 0; i < getNumberOfVertices(user); i++) {
        for (int j = 0; j < getNumberOfVertices(user); j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < getNumberOfEdges(user); i++) {
        int vertice1 = edges[i][0] - 1;
        int vertice2 = edges[i][1] - 1;
        adjacencyMatrix[vertice1][vertice2] = 1;
        adjacencyMatrix[vertice2][vertice1] = 1;
    }
   /* cout << "------------------MACIERZ S¥SIEDZTWA-----------------" << endl;
    for (int i = 0; i < getNumberOfVertices(user); i++) {
        for (int j = 0; j < getNumberOfVertices(user); j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }*/
    return adjacencyMatrix;
}
