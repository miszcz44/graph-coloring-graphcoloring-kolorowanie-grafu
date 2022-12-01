#include <iostream>
#include <stdlib.h>
#include <string>
#include "FileReader.h"
#include "generator.h"
#include "Graph.h"


using namespace std;

int main()
{
    Generator generator(17, 111);
    //generator.setEdges(generator.generateEdges(generator.getNumberOfVertices(), generator.getNumberOfEdges()));
    //generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges());

    FileReader fileReader("Tekst.txt");
    generator.setNumberOfEdges(fileReader.readNumberOfEdgesFromFile(fileReader.getFilePath()));
    generator.setNumberOfVertices(fileReader.readNumberOfVerticesFromFile(fileReader.getFilePath()));
    generator.setEdges(fileReader.readEdgesFromFile(fileReader.getFilePath()));
    generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges());

    Graph graph(generator.getNumberOfVertices(), generator.getEdges());
    graph.greedyColoring(graph.getNumberOfVertices(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));

    return 0;
}