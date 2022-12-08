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

class GraphGeneticReady() {
    vector<int> Individual;
    vector<vector<int>> Population;
    int Generation;
    int NumberOfColors;
    int Fitness;
public:
    GraphGeneticReady(vector<int> individual, vector<vector<int>> population, int generation, int num, int fitness);
    void GeneticAlgorithm(int numberOfVertices, int** adjacencyMatrix);
    void SetPopulation();
    vector<vector<int>> GetPopulation();
    void SetNumberOfColors(int** adjacencyMatrix);
    int GetNumberOfColors();
    void SetIndividual();
    vector<int> GetIndividual();
    void SetFitness(int** adjacencyMatrix, vector<int> individual);
    int GetFitness();
    tuple< vector<int>, vector<int> > Crossover(int parent1, int parent2);
    vector<int> Mutation1(vector<int> individual);
    vector<int> Mutation2(vector<int> individual);
};