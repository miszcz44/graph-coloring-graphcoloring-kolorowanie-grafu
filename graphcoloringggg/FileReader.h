#include <iostream>
#include <stdlib.h>
#include <string>


using std::string;

class FileReader {

    string filePath;

public:
    FileReader(string filePath);
    ~FileReader();
    void setFilePath(string filePath);
    string getFilePath();
    int readNumberOfVerticesFromFile(string filePath);
    int readNumberOfEdgesFromFile(string filePath);
    int** readEdgesFromFile(string filePath);

};
