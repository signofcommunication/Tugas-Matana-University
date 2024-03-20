#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Fungsi untuk membaca data tunggal berdasarkan nomor baris
string readDataByLineNumber(const string& filename, int lineNumber) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        int currentLineNumber = 0;
        while (getline(file, line)) {
            currentLineNumber++;
            if (currentLineNumber == lineNumber) {
                return line;
            }
        }
        // Jika nomor baris tidak ditemukan
        cerr << "Nomor baris tidak ditemukan." << endl;
        file.close();
    } else {
        cerr << "Gagal membuka file: " << filename << endl;
    }
    return ""; // Return empty string jika tidak ada data yang ditemukan
}

void read_single(int lineNumber) {
    string filename = "database.txt";

    string data = readDataByLineNumber(filename, lineNumber);
    if (!data.empty()) {
        cout << "Data pada baris " << lineNumber << ": " << data << endl;
    }
}
