#include <iostream>
#include <stdlib.h>
#include <string>
#include "generator.h"
#include "UserControl.h"
#include <fstream>


using std::string;

class FileReader : public Generator {

public:

    string getFilePath(UserControl user);
    int readNumberOfVerticesFromFile(UserControl user);
    int readNumberOfEdgesFromFile(UserControl user);
    int** readEdgesFromFile(UserControl user);

};
