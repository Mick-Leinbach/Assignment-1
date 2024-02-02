#include "Assignment_1.h"

int main() {
	string contents;
	
	// Attempt to open A1input.txt
	fstream inFile;
	inFile.open("A1input.txt");
	if (!inFile.is_open()) {
		cout << "Input file invalid.";
	}

	// Print out each line of file
	while (getline(inFile, contents)) {
		cout << contents << endl;
	}

	// Close file
	inFile.close();
}