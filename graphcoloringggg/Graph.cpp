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

    for (int u = 0; u < numberOfVertices; u++) {
        cout << "Color: " << u+1 << ", Assigned with Color: " << color[u] << endl;
    }
}

int get_random_number(int a, int z) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(a, z);
    return distr(gen);
}

float get_random_float(float a, float z) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distr(a, z);
    return distr(gen);
}

int sum(int a[], int n) {
    int initial_sum = 0;
    return accumulate(a, a + n, initial_sum);
}

GraphGeneticReady::GraphGeneticReady(vector<int> individual, vector<vector<int>> population, int generation, int num, int fitness, int populationSize) {
    Individual = individual;
    Population = population;
    Generation = generation;
    NumberOfColors = num;
    Fitness = fitness;
    PopulationSize = populationSize;
};

GraphGeneticReady::GraphGeneticReady(int generation, int num, int fitness, int vertices, int populationSize) {
    Generation = generation;
    NumberOfColors = num;
    Fitness = fitness;
    numberOfVertices = vertices;
    PopulationSize = populationSize;
}

GraphGeneticReady::~GraphGeneticReady() {
    
}



void GraphGeneticReady::SetPopulation(){
    int generation = 0;
    vector<vector<int>> population;
    for (int i = 0; i < getPopulationSize(); i++) {
        vector<int> individual = GetIndividual();
        //cout << individual[15];
        population.push_back(individual);
        //cout << population[i][0];
        //cout << individual[0] << " " << individual[1] << " " << individual[2] << " " << individual[3] << endl;

    }
    Population = population;

}

vector<vector<int>> GraphGeneticReady::GetPopulation() {
    return Population;
}

int GraphGeneticReady::getPopulationSize() {
    return PopulationSize;
}


//vector<vector<int>> GraphGeneticReady::GetPopulation() {

//}

void GraphGeneticReady::SetNumberOfColors(int **adjacencyMatrix) {
    int maxNumberOfColors = 1;
    int counter = 0;
    for (int i = 0; i < getNumberOfVertices(); i++) {
        for (int j = 0; j < getNumberOfVertices(); j++) {
            if (adjacencyMatrix[i][j] == 1) {
                counter++;
            }
        }
        if (counter > maxNumberOfColors) {
            maxNumberOfColors = counter;
        }
        counter = 0;
    }
    //NumberOfColors = maxNumberOfColors + 1;
    NumberOfColors = 100;
}

int GraphGeneticReady::GetNumberOfColors() {
    return NumberOfColors;
}

vector<int> GraphGeneticReady::GetIndividual() {
    vector<int> individual;
    for (int i = 0; i < getNumberOfVertices(); i++) {
        individual.push_back(get_random_number(1, GetNumberOfColors()));
    }
    return individual;
}

//vector<int> GraphGeneticReady::GetIndividual() {
//    return Individual;
//}

int GraphGeneticReady::GetFitness(int** adjacencyMatrix, vector<int> individual) {
    int fitness = 0;
    for (int i = 0; i < getNumberOfVertices(); i++) {
        for (int j = i+1; j < getNumberOfVertices(); j++) {
            if (individual[i] == individual[j] and adjacencyMatrix[i][j] == 1) {
                fitness++;
           }
        }
    }
    //cout << fitness;
    Fitness = fitness;
    return fitness;
}

//int GraphGeneticReady::GetFitness() {
//    return Fitness;
//}

tuple< vector<int>, vector<int> > GraphGeneticReady::Crossover(vector<int> parent1, vector<int> parent2) {
    int position = get_random_number(2, getNumberOfVertices() - 2);
    //cout << position << endl;
    vector<int> child1, child2;
    //cout << "a" << endl;
    for (int i = 0; i < position + 1; i++) {
        child1.push_back(parent1[i]);
        child2.push_back(parent2[i]);
    }
    
    for (int j = position + 1; j < getNumberOfVertices(); j++) {
        child1.push_back(parent2[j]);
        child2.push_back(parent1[j]);
    }
    //cout << "b" << endl;
    return make_tuple(child1, child2);
}

vector<int> GraphGeneticReady::Mutation1(vector<int> individual, int** adjacencyMatrix) {
    for (int i = 0; i < getNumberOfVertices(); i++) {
        //cout << "c" << endl;
        vector<int> adjacentColors;
        int numberOfAdjacentColors = 0;
        for (int j = i+1; j < getNumberOfVertices(); j++) {
            if (adjacencyMatrix[i][j] == 1 and individual[i] == individual[j]) {
                adjacentColors.push_back(individual[i]);
                numberOfAdjacentColors++;
            }
        }
        //cout << "d" << endl;
        if (numberOfAdjacentColors != 0) {
            vector<int> validColors;
            for (int j = 1; j < GetNumberOfColors(); j++) {
                validColors.push_back(j);
                //cout << validColors[j-1] << " ";
            }
            
            for (int j = 0; j < numberOfAdjacentColors; j++) {
                validColors.erase(std::remove(validColors.begin(), validColors.end(), adjacentColors[j]), validColors.end());
                //cout << "-";
            }
            int newColorPosition = rand() % validColors.size();
            int newColor = validColors[newColorPosition];
            individual[i] = newColor;
        }
    }
    return individual;
}

vector<int> GraphGeneticReady::Mutation2(vector<int> individual, int** adjacencyMatrix) {
    vector<int> validColors;
    for (int j = 1; j < GetNumberOfColors(); j++) {
        validColors.push_back(j);
        //cout << validColors[j-1] << " ";
    }
    for (int i = 0; i < getNumberOfVertices(); i++) {
        for (int j = 0; j < getNumberOfVertices(); j++) {
            if (adjacencyMatrix[i][j] == 1 and individual[i] == individual[j]) {
                int newColorPosition = rand() % validColors.size();
                int newColor = validColors[newColorPosition];
                individual[i] = newColor;
            }
        }
    }
    
    return individual;
}


vector<vector<int>> GraphGeneticReady::TournamentSelection(vector<vector<int>> population, int** adjacencyMatrix) {
    vector<vector<int>> new_population;
    for (int i = 0; i < 2; i++) {
        random_device rd;
        mt19937 g(rd());
        shuffle(population.begin(), population.end(), g);
        for (int j = 0; j < getPopulationSize() - 1; j += 2) {
            if (GetFitness(adjacencyMatrix, population[j]) < GetFitness(adjacencyMatrix, population[j+1])) {
                new_population.push_back(population[j]);
            }
            else {
                new_population.push_back(population[j+1]);
            }
        }
    }
    return new_population;
}

void GraphGeneticReady::GeneticAlgorithm(int numberOfVertices, int** adjacencyMatrix) {
    SetNumberOfColors(adjacencyMatrix);
    SetPopulation();
    int bestFitness = GetFitness(adjacencyMatrix, GetPopulation()[0]);
    vector<int> fittestIndividual = GetPopulation()[0];
    int gen = 1;
    vector<int> child1, child2;
    random_device rd;
    mt19937 g(rd());
    while (bestFitness != 0 and gen != 10000) {
        /*if (gen % 50 == 0) {
            for (int i = 0; i < 10; i++) {
                Population.pop_back();
            }
            for (int i = 0; i < 10; i++) {
                Population.push_back(GetIndividual());
            }
        }*/
        gen++;
        //Population = TournamentSelection(GetPopulation(), adjacencyMatrix);
        vector<vector<int>> new_population;
        shuffle(Population.begin(), Population.end(), g);
        
        for(int i = 0; i < getPopulationSize() - 1; i = i + 2) {

            if (bestFitness < 5) {
                tie(child1, child2) = Crossover(fittestIndividual, fittestIndividual);
            }
            else {
                int possibleParent1 = rand() % Population.size();
                int possibleParent2 = rand() % Population.size();
                int possibleParent3 = rand() % Population.size();
                int possibleParent4 = rand() % Population.size();
                vector<int> parent1, parent2;
                if (GetFitness(adjacencyMatrix, Population[possibleParent1]) > GetFitness(adjacencyMatrix, Population[possibleParent2])) {
                    parent1 = Population[possibleParent2];
                }
                else {
                    parent1 = Population[possibleParent1];
                }
                if (GetFitness(adjacencyMatrix, Population[possibleParent3]) > GetFitness(adjacencyMatrix, Population[possibleParent4])) {
                    parent2 = Population[possibleParent4];
                }
                else {
                    parent2 = Population[possibleParent3];
                }
                tie(child1, child2) = Crossover(parent1, parent2);
            }
            new_population.push_back(child1);
            new_population.push_back(child2);
        }
        for (int i = 0; i < getPopulationSize(); i++) {
            if (bestFitness >= 5) {
                //cout << "adsa" << endl;
                //cout << i << endl;
                new_population[i] = Mutation1(new_population[i], adjacencyMatrix);
                //cout << "sss" << endl;
            }
            else {
                new_population[i] = Mutation2(new_population[i], adjacencyMatrix);
            }
        }
        Population = new_population;
        bestFitness = GetFitness(adjacencyMatrix, Population[0]);
        fittestIndividual = Population[0];
        for (vector<int> individual : Population) {
            if (GetFitness(adjacencyMatrix, individual) < bestFitness) {
                bestFitness = GetFitness(adjacencyMatrix, individual);
                fittestIndividual = individual;
            }
        }
        if (gen % 10 == 0 or bestFitness == 0) {
            cout << "Generation: " << gen << " Best Fitness: " << bestFitness << endl;
            for (int nmb : fittestIndividual) {
                cout << nmb << " ";
            }
            cout << endl;
            cout << getPopulationSize();
        }
        
    }

}