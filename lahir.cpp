#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
	ifstream myfile;
	myfile.open("./datalahir.txt");
	string myline;
	
	if ( myfile.is_open() ) {
		while ( myfile ) { // equivalent to myfile.good()
			getline (myfile, myline);
			cout << myline << '\n';
		}
	}
	else {
	cout << "Couldn't open file\n";
	}
	return 0;
}
