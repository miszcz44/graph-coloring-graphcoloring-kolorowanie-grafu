#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Graph
{
    int** Edges;
protected:
    int numberOfVertices;    
public:

    Graph(int vertices, int** edges);
    Graph();
    ~Graph();
    int getNumberOfVertices();
    int** getEdges();
    void setNumberOfVertices(int vertices);
    void setEdges(int** edges);
    void greedyColoring(int numberOfVertices, int** adjacencyMatrix);
};

class GraphGeneticReady: Graph{
    vector<int> Individual;
    vector<vector<int>> Population;
    int Generation;
    int NumberOfColors;
    int Fitness;
    int PopulationSize;

public:
    GraphGeneticReady(vector<int> individual, vector<vector<int>> population, int generation, int num, int fitness, int populationSize);
    GraphGeneticReady(int generation, int num, int fitness, int vertices, int populationSize);
    ~GraphGeneticReady();
    void GeneticAlgorithm(int numberOfVertices, int** adjacencyMatrix);
    void SetPopulation();
    int getPopulationSize();
    vector<vector<int>> GetPopulation();
    //vector<vector<int>> GetPopulation();
    void SetNumberOfColors(int** adjacencyMatrix);
    int GetNumberOfColors();
    vector<int> GetIndividual();
    //vector<int> GetIndividual();
    int GetFitness(int** adjacencyMatrix, vector<int> individual);
    //int GetFitness();
    tuple< vector<int>, vector<int> > Crossover(vector<int> parent1, vector<int> parent2);
    vector<int> Mutation1(vector<int> individual);
    vector<int> Mutation2(vector<int> individual);
    vector<vector<int>> TournamentSelection(vector<vector<int>> population, int** adjacencyMatrix);
};