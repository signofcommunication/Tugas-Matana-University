#include <iostream>
#include <fstream>
#include <string>

// Fungsi untuk membaca data tunggal berdasarkan nomor baris
std::string readDataByLineNumber(const std::string& filename, int lineNumber) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        int currentLineNumber = 0;
        while (std::getline(file, line)) {
            currentLineNumber++;
            if (currentLineNumber == lineNumber) {
                return line;
            }
        }
        // Jika nomor baris tidak ditemukan
        std::cerr << "Nomor baris tidak ditemukan." << std::endl;
        file.close();
    } else {
        std::cerr << "Gagal membuka file: " << filename << std::endl;
    }
    return ""; // Return empty string jika tidak ada data yang ditemukan
}

void read_single(int lineNumber) {
    std::string filename = "database.txt";

    std::string data = readDataByLineNumber(filename, lineNumber);
    if (!data.empty()) {
        std::cout << "Data pada baris " << lineNumber << ": " << data << std::endl;
    }
}

