#include "stack.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv []) {
    string line, word;
	
	if(argc == 2) {
		fstream file;
		
		file.open(argv[1]);
		
		while(getline(file, line)) {
			istringstream iss(line);
		
			while(iss >> word) if(Operation(word) == -1) break;
		}
		file.close();
	}
	else {
		cout << "***Type '?', 'h' or 'help' for help***" << endl;
		cout << "[" << StackSize() << "] ";
	
		while(getline(cin, line)) {
			istringstream iss(line);
		
			while(iss >> word) if(Operation(word) == -1) break;
		
			cout << "[" << StackSize() << "] ";
		}
	}
    return 0;
}