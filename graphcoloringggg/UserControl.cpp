#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "UserControl.h"

using namespace std;

void invalidInputControl() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Niepoprawne dane, spróbuj jeszcze raz: ";
}

void UserControl::userInterface() {
    string choice1;
    cout << "Wybierz opcje:\n1.Graf tworzony losowo\n2.Graf tworzony z pliku\n";
    cin >> choice1;
    while (choice1.compare("1") != 0 and choice1.compare("2") != 0) {
        invalidInputControl();
        cin >> choice1;
    }
    if (choice1.compare("1") == 0) {
        int vertices;
        cout << "Podaj liczbê wierzcho³ków: ";
        bool isValid = false;
        cin >> vertices;
        while (isValid == false) {
            if (cin.good()) {
                if (vertices > 1) {
                    isValid = true;
                }
                else {
                    invalidInputControl();
                    cin >> vertices;
                }
            }
            else {
                invalidInputControl();
                cin >> vertices;
            }
        }
        setNumberOfVertices(vertices);
        int edges;
        cout << "Podaj liczbê krawêdzi: ";
        isValid = false;
        cin >> edges;
        while (isValid == false) {
            if (cin.good()) {
                if (edges <= vertices*(vertices-1)/2 and edges >= 0) {
                    isValid = true;
                }
                else {
                    invalidInputControl();
                    cin >> edges;
                }
            }
            else {
                invalidInputControl();
                cin >> edges;
            }
        }
        setNumberOfEdges(edges);

    }
    else if (choice1.compare("2") == 0) {
        userChoiceFile = true;
        string filePath;
        cout << "Podaj nazwê pliku: ";
        cin >> filePath;
        ifstream file;
        file.open(filePath);
        while (!file) {
            invalidInputControl();
            cin >> filePath;
            file.open(filePath);
        }
        setFilePath(filePath);
    }
    
}

void UserControl::setNumberOfEdges(int edges) {
    numberOfEdges = edges;
}

void UserControl::setNumberOfVertices(int vertices) {
    numberOfVertices = vertices;
}

void UserControl::setFilePath(string path) {
    filePath = path;
}

string UserControl::getFilePath() {
    return filePath;
}

bool UserControl::getUserChoiceFile() {
    return userChoiceFile;
}
