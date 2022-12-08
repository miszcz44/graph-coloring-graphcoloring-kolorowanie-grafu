#include <iostream>
#include <stdlib.h>
#include "Graph.h"
#include <vector>
#include <random>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;

Graph::Graph(int vertices, int** edges) {
	numberOfVertices = vertices;
	Edges = edges;
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

    for (int u = 0; u < numberOfVertices; u++) {
        cout << "Color: " << u+1 << ", Assigned with Color: " << color[u] << endl;
    }
}

int get_random_number(int a, int z) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(a, z)
        return distr(gen);
}

float get_random_float(float a, float z) {
    random_device rd;
    uniform_real_distribution<float> distr(a, z)
        return distr(gen);
}

int sum(int a[], int n) {
    int initial_sum = 0;
    return accumulate(a, a + n, initial_sum);
}

GraphGeneticReady::GraphGeneticReady(vector<int> individual, vector<vector<int>> population, int generation, int num, int fitness) {
    Individual = individual;
    Population = population;
    Generation = generation;
    NumberOfColors = num;
    Fitness = fitness;
};

void GraphGeneticReady::GeneticAlgorithm(int numberOfVertices, int** adjacencyMatrix) {
    
}

void GraphGeneticReady::SetPopulation(){
    int population_size = 200;
    int generation = 0;
    vector<vector<int>> population(population_size, vector<int>(getNumberOfVertices(), 0);
    for (int i = 0; i < population_size; i++) {
        vector<int> individual = SetIndividual();
        population.push_back(individual);
    }
    Population = population;
}

vector<vector<int>> GraphGeneticReady::GetPopulation() {

}

void GraphGeneticReady::SetNumberOfColors(int** adjacencyMatrix) {
    int maxNumberOfColors = 1;
    for (int i = 0; i < getNumberOfVertices(); i++) {
        if (sum(adjacencyMatrix[i], sizeof(adjacencyMatrix[i]) / sizeof(adjacencyMatrix[0][0])) > maxNumberOfColors) {
            maxNumberOfColors = (sum(adjacencyMatrix[i], sizeof(adjacencyMatrix[i]) / sizeof(adjacencyMatrix[0][0]) + 1;
        }
    }
    NumberOfColors = maxNumberOfColors;
}

int GraphGeneticReady::GetNumberOfColors() {
    return NumberOfColors;
}

void GraphGeneticReady::SetIndividual() {
    for (int i = 0; i < getNumberOfVertices(); i++) {
        Individual.push_back(get_random_number(1, GetNumberOfColors()));
    }
}

vector<int> GraphGeneticReady::GetIndividual() {
    return Individual;
}

void GraphGeneticReady::SetFitness(int** adjacencyMatrix, vector<int> individual) {
    int fitness = 0;
    for (int i = 0, i < getNumberOfVertices(); i++) {
        for (int j = i; j < getNumberOfVertices(); j++) {
            if (individual[i] == individual[j] and adjacencyMatrix[i][j] == 1) {
                fitness++;
           }
        }
    }
    Fitness = fitness;
}

int GraphGeneticReady::GetFitness() {
    return Fitness;
}

tuple< vector<int>, vector<int> > GraphGeneticReady::Crossover(int parent1, int parent2) {
    int position = get_random_number(2, getNumberOfVertices() - 2);
    vector<int> child1, child2;
    for (int i = 0; i < position + 1; i++) {
        child1.push_back(parent1[i]);
        child2.push_back(parent2[i]);
    }
    for (int j = position + 1; j < getNumberOfVertices(); j++) {
        child1.push_back(parent2[j]);
        child2.push_back(parent1[j]);
    }
    return make_tuple(child1, child2);
}

vector<int> GraphGeneticReady::Mutation1(vector<int> individual) {
    float probability = 0.4;
    float check = get_random_float(0, 1);
    if (check <= probability) {
        int position = get_random_number(0, getNumberOfVertices() - 1);
        individual[position] = get_random_number(1, GetNumberOfColors());
    }
    return individual;
}

vector<int> GraphGeneticReady::Mutation2(vector<int> individual) {
    float probability = 0.2;
    float check = get_random_float(0, 1);
    if (check <= probability) {
        int position = get_random_number(0, getNumberOfVertices() - 1);
        individual[position] = get_random_number(1, GetNumberOfColors());
    }
    return individual;
}


/*
vector<int> TournamentSelection(vector<int> population) {
    vector<int> new_population;
    for (int i = 0; i < 2; i++) {
        auto rng = default_random_engine{};
        shuffle(begin(population), end(population), rng);
        
    }
}
*/