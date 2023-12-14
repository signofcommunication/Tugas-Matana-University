#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() 
    ifstream inputFile("game_data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    vector<string> mapData;
    string line;

    while (getline(inputFile, line)) {
        mapData.push_back(line);
    }

    inputFile.close();

    int M = mapData.size();

    vector<vector<char> > map(M, vector<char>(M));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            map[i][j] = mapData[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == '*') {
                cout << "Bomb location: " << i << " " << j << endl;
            }
        }
    }

    cout << "Bomb not found in the map." << endl;

    return 0;
}

