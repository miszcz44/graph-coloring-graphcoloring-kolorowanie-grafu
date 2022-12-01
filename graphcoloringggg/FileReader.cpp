#include <iostream>
#include <stdlib.h>
#include "FileReader.h"
#include <fstream>

using namespace std;

FileReader::FileReader(string path) {
    filePath = path;
}

FileReader::~FileReader() {

}

string FileReader::getFilePath() {
    return filePath;
}

void FileReader::setFilePath(string path) {
    filePath = path;
}

int FileReader::readNumberOfVerticesFromFile(string filePath) {
    fstream file(filePath);
    int numberOfVertices;
    string fileText;
    getline(file, fileText);
    numberOfVertices = stoi(fileText);
    file.close();
    return numberOfVertices;
}

int FileReader::readNumberOfEdgesFromFile(string filePath) {
    fstream file(filePath);
    int numberOfEdges = 0;
    string fileText;
    getline(file, fileText);
    while (getline(file, fileText)) {
        numberOfEdges++;
    }
    file.close();
    return numberOfEdges;
}

int** FileReader::readEdgesFromFile(string filePath) {
    fstream file(filePath);
    int numberOfVertices;
    string fileText;
    getline(file, fileText);
    numberOfVertices = stoi(fileText);
    int numberOfEdges = readNumberOfEdgesFromFile(filePath);
    int** edges = new int* [numberOfEdges];
    for (int i = 0; i < numberOfEdges; i++) {
        edges[i] = new int[2];
    }
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
    return edges;
}