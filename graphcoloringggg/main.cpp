#include <iostream>
#include <stdlib.h>
#include <string>
#include "FileReader.h"
#include "generator.h"
#include "Graph.h"
#include <vector>
#include <random>
#include <tuple>
#include <numeric>
#include <algorithm>


using namespace std;

int gett_random_number(int a, int z) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distr(a, z);
    cout << distr(gen);
    return distr(gen);
}

int main()
{
    Generator generator(17, 111);
    //generator.setEdges(generator.generateEdges(generator.getNumberOfVertices(), generator.getNumberOfEdges()));
    //generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges());

    FileReader fileReader("Tekst.txt");
    generator.setNumberOfEdges(fileReader.readNumberOfEdgesFromFile(fileReader.getFilePath()));
    generator.setNumberOfVertices(fileReader.readNumberOfVerticesFromFile(fileReader.getFilePath()));
    generator.setEdges(fileReader.readEdgesFromFile(fileReader.getFilePath()));
    //generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges());

    //Graph graph(generator.getNumberOfVertices(), generator.getEdges());
    //graph.greedyColoring(graph.getNumberOfVertices(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));
    Graph graph(generator.getNumberOfVertices(), generator.getEdges());

    //gett_random_number(0, 53);
    //cout << graph.getNumberOfVertices();
    GraphGeneticReady graphGeneticReady(0, 0, 0, graph.getNumberOfVertices(), 200);
    graphGeneticReady.SetNumberOfColors(generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));
    graphGeneticReady.SetPopulation();
    graphGeneticReady.GetFitness(generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()), graphGeneticReady.GetIndividual());
    graphGeneticReady.TournamentSelection(graphGeneticReady.GetPopulation(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));


    return 0;
}