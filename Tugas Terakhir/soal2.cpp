#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool hasCapitalLetter(const string& word) {
    for (char ch : word) {
        if (isupper(ch)) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream inputFile("testdata.in");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;

        while (ss >> word) {
            if (!hasCapitalLetter(word)) {
                cout << word << endl;
            }
        }

        if (!hasCapitalLetter(line)) {
            break;
        }
    }

    inputFile.close();

    return 0;
}

