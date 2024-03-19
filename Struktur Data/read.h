#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readFile(string file_name) {
	ifstream file(file_name);
	string line;
	
	if(!file.is_open()) {
		cout << "Failed to open the file." << endl;
	}
	
	while(getline(file,line)) {
		cout << line << endl;
	}
	
	file.close();
}
