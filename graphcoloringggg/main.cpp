#include <iostream>
#include <stdlib.h>
#include <string>
#include "FileReader.h"
#include "generator.h"
#include "UserControl.h"
#include "Graph.h"
#include "GraphGeneticReady.h"
#include <vector>
#include <random>
#include <tuple>
#include <numeric>
#include <algorithm>


using namespace std;



int main()
{
   // Generator generator{};
   // //generator.setEdges(generator.generateEdges(generator.getNumberOfVertices(), generator.getNumberOfEdges()));
   // //generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges());

   // FileReader fileReader("Tekst.txt");
   // UserControl userControl{};
   // userControl.setNumberOfEdges(fileReader.readNumberOfEdgesFromFile(fileReader.getFilePath()));

   // userControl.setNumberOfVertices(fileReader.readNumberOfVerticesFromFile(fileReader.getFilePath()));

   // generator.setEdges(fileReader.readEdgesFromFile(fileReader.getFilePath()));

   // //generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges());

   // //Graph graph(generator.getNumberOfVertices(), generator.getEdges());
   // //graph.greedyColoring(graph.getNumberOfVertices(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));
   // Graph graph(generator.getNumberOfVertices(), generator.getEdges());
   // 

   // //gett_random_number(0, 53);
   // //cout << graph.getNumberOfVertices();
   // GraphGeneticReady graphGeneticReady(0, 0, 0, graph.getNumberOfVertices(), 50);

   ///* graphGeneticReady.SetNumberOfColors(generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));
   // graphGeneticReady.SetPopulation();
   // graphGeneticReady.GetFitness(generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()), graphGeneticReady.GetIndividual());
   // graphGeneticReady.TournamentSelection(graphGeneticReady.GetPopulation(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));*/
   // graphGeneticReady.GeneticAlgorithm(graph.getNumberOfVertices(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));

   // //graph.greedyColoring(graph.getNumberOfVertices(), generator.generateAdjacencyMatrix(generator.getNumberOfVertices(), generator.getEdges()));

    FileReader fileReader{};
    UserControl user{};
    user.userInterface();
    Generator generator{};
    Graph graph(generator.getNumberOfVertices(user));
    if (user.getUserChoiceFile()) {
        user.setNumberOfEdges(fileReader.readNumberOfEdgesFromFile(user));
        user.setNumberOfVertices(fileReader.readNumberOfVerticesFromFile(user));
        graph.greedyColoring(generator.getNumberOfVertices(user), generator.generateAdjacencyMatrix(fileReader.readEdgesFromFile(user), user));
        GraphGeneticReady graphGeneticReady(50, generator.getNumberOfVertices(user));
        graphGeneticReady.GeneticAlgorithm(generator.generateAdjacencyMatrix(fileReader.readEdgesFromFile(user), user));

    }
    else {
        graph.greedyColoring(generator.getNumberOfVertices(user), generator.generateAdjacencyMatrix(generator.generateEdges(user), user));
        GraphGeneticReady graphGeneticReady(100, generator.getNumberOfVertices(user));
        graphGeneticReady.GeneticAlgorithm(generator.generateAdjacencyMatrix(generator.generateEdges(user), user));
    }
    return 0;
}