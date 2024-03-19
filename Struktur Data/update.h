#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Fungsi untuk membaca keseluruhan file ke dalam string
string bacaFile(const string& filename) {
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
void writeFile(const string& content, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Data berhasil disimpan ke dalam file: " << filename << endl;
    } else {
        cerr << "Gagal membuka file: " << filename << endl;	
    }
}

// Fungsi untuk mengedit data berdasarkan nomor baris
void editDataByLineNumber(const string& filename, int lineNumber) {
   string content = bacaFile(filename);
    if (!content.empty()) {
        string newData;
        cin.ignore(); // Membersihkan newline dari buffer sebelumnya
        cout << "Masukkan data baru untuk baris " << lineNumber << ": ";
        getline(cin, newData);

        // Temukan posisi awal dan akhir baris yang ingin diubah
        size_t startPos = 0;
        size_t endPos = content.find('\n');
        for (int i = 1; i < lineNumber && endPos != string::npos; ++i) {
            startPos = endPos + 1;
            endPos = content.find('\n', startPos);
        }

        // Jika nomor baris valid, lakukan perubahan
        if (endPos != string::npos) {
            content.replace(startPos, endPos - startPos, newData);
            writeFile(content, filename);
            cout << "Data berhasil diperbarui untuk baris " << lineNumber << endl;
        } else {
            cerr << "Nomor baris tidak valid." << std::endl;
        }
    }
}

void updateData(int line_number) {
    editDataByLineNumber("database.txt", line_number);
}

