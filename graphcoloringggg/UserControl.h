#include <iostream>
#include <stdlib.h>
#pragma once

using std::string;

class UserControl {

	int numberOfVertices;
	int numberOfEdges;
	string filePath;
	bool userChoiceFile = false;

public:
	void userInterface();
	void setNumberOfVertices(int vertices);
	void setNumberOfEdges(int edges);
	void setFilePath(string path);
	string getFilePath();
	bool getUserChoiceFile();
	friend class Generator;
	friend class FileReader;
};
