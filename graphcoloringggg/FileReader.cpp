#include <iostream>
#include <stdlib.h>
#include "FileReader.h"
#include <fstream>

using namespace std;



string FileReader::getFilePath(UserControl user) {
    return user.filePath;
}

int FileReader::readNumberOfVerticesFromFile(UserControl user) {
    string filePath = getFilePath(user);
    fstream file(filePath);
    int numberOfVertices;
    string fileText;
    getline(file, fileText);
    numberOfVertices = stoi(fileText);
    file.close();
    return numberOfVertices;
}

int FileReader::readNumberOfEdgesFromFile(UserControl user) {
    string filePath = getFilePath(user);
    fstream file(filePath);
    string fileText;
    getline(file, fileText);
    int numberOfEdges = 0;
    while (getline(file, fileText)) {
        numberOfEdges++;
    }
    file.close();
    return numberOfEdges;
}

int** FileReader::readEdgesFromFile(UserControl user) {
    string filePath = getFilePath(user);
    fstream file(filePath);
    int numberOfVertices;
    string fileText;
    getline(file, fileText);
    numberOfVertices = stoi(fileText);
    int numberOfEdges = readNumberOfEdgesFromFile(user);
    int** edges = generateMatrix(numberOfEdges);
    int cnt = 0;
    char c;
    string vertice = "";
    while (file.get(c) && c) {
        if (c == ' ') {
            edges[cnt][0] = stoi(vertice);
            vertice = "";
        }
        else if(c == '\n') {
            edges[cnt][1] = stoi(vertice);
            vertice = "";
            cnt++;
        }
        else {
            vertice = vertice + c;
        }
    }
    file.close();
    return edges;
}