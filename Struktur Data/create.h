#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createNew(string name,string major,string age,string gpa) {
	ofstream file("database.txt",ios::app);
	string hasil;
	
	if(!file.is_open()) {
		cerr << "Failed to open the file." << endl;
	}
	
	hasil += "6";
	hasil += ",";
	hasil += name;
	hasil += ",";
	hasil += major;
	hasil += ",";
	hasil += age;
	hasil += ",";
	hasil += gpa;
	file << "\n" << hasil;
	
	file.close();
	
	cout << "Data Mahasiswa baru telah berhasil ditambahkan!" << endl;
}
