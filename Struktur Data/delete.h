#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Fungsi untuk membaca keseluruhan file ke dalam string
string bacaFiles(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file.close();
        return content;
    } else {
        cerr << "Gagal membuka file: " << filename << endl;
        return "";
    }
}

// Fungsi untuk menulis string ke dalam file
void tulisFile(const string& content, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Data berhasil disimpan ke dalam file: " << filename << endl;
    } else {
        cerr << "Gagal membuka file: " << filename << endl;
    }
}

// Fungsi untuk menghapus data berdasarkan nomor baris
void deleteDataByLineNumber(const string& filename, int lineNumber) {
    string content = bacaFiles(filename);
    if (!content.empty()) {
        stringstream ss(content);
        string newContent;
        string line;
        int currentLineNumber = 1;
        while (getline(ss, line)) {
            if (currentLineNumber != lineNumber) {
                newContent += line + "\n";
            }
            currentLineNumber++;
        }
        tulisFile(newContent, filename);
        cout << "Baris " << lineNumber << " berhasil dihapus." << endl;
    }
}

void deleteData(int lineNumber) {
    deleteDataByLineNumber("database.txt", lineNumber);
}
