#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Fungsi untuk membaca keseluruhan file ke dalam string
std::string bacaFiles(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    } else {
        std::cerr << "Gagal membuka file: " << filename << std::endl;
        return "";
    }
}

// Fungsi untuk menulis string ke dalam file
void tulisFile(const std::string& content, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "Data berhasil disimpan ke dalam file: " << filename << std::endl;
    } else {
        std::cerr << "Gagal membuka file: " << filename << std::endl;
    }
}

// Fungsi untuk menghapus data berdasarkan nomor baris
void deleteDataByLineNumber(const std::string& filename, int lineNumber) {
    std::string content = bacaFiles(filename);
    if (!content.empty()) {
        std::stringstream ss(content);
        std::string newContent;
        std::string line;
        int currentLineNumber = 1;
        while (std::getline(ss, line)) {
            if (currentLineNumber != lineNumber) {
                newContent += line + "\n";
            }
            currentLineNumber++;
        }
        tulisFile(newContent, filename);
        std::cout << "Baris " << lineNumber << " berhasil dihapus." << std::endl;
    }
}

void deleteData(int lineNumber) {
    deleteDataByLineNumber("database.txt", lineNumber);
}

