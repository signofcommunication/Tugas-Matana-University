#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    int id;
    std::string nama;
    std::string jurusan;
    int usia;
    double ipk;
};

// Fungsi untuk membandingkan dua mahasiswa berdasarkan nama (untuk digunakan dalam sort)
// Fungsi untuk membandingkan dua mahasiswa berdasarkan nama (untuk digunakan dalam sort)
bool compareByNama(const Mahasiswa& a, const Mahasiswa& b) {
    // Mengambil inisial dari nama
    char initialA = std::toupper(a.nama[0]);
    char initialB = std::toupper(b.nama[0]);
    
    // Jika inisial sama, bandingkan nama secara lengkap
    if (initialA == initialB) {
        return a.nama < b.nama;
    }
    
    // Jika inisial berbeda, urutkan berdasarkan inisial
    return initialA < initialB;
}


// Fungsi untuk memuat data dari file
// Fungsi untuk memuat data dari file
std::vector<Mahasiswa> loadMahasiswa(const std::string& filename) {
    std::vector<Mahasiswa> mahasiswas;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            Mahasiswa mahasiswa;
            int tokenCount = 0;
            while (std::getline(iss, token, ',')) {
                tokenCount++;
                std::istringstream tokenStream(token);
                switch (tokenCount) {
                    case 1:
                        tokenStream >> mahasiswa.id;
                        break;
                    case 2:
                        std::getline(tokenStream, mahasiswa.nama, '"');
                        std::getline(tokenStream, mahasiswa.nama, '"');
                        break;
                    case 3:
                        std::getline(tokenStream, mahasiswa.jurusan, '"');
                        std::getline(tokenStream, mahasiswa.jurusan, '"');
                        break;
                    case 4:
                        tokenStream >> mahasiswa.usia;
                        break;
                    case 5:
                        tokenStream >> mahasiswa.ipk;
                        break;
                }
            }
            mahasiswas.push_back(mahasiswa);
        }
        file.close();
    } else {
        std::cerr << "Gagal membuka file: " << filename << std::endl;
    }
    return mahasiswas;
}


// Fungsi untuk menampilkan data mahasiswa
void displayMahasiswa(const std::vector<Mahasiswa>& mahasiswas) {
    for (const auto& mahasiswa : mahasiswas) {
        std::cout << "ID: " << mahasiswa.id << ", Nama: " << mahasiswa.nama << ", Jurusan: " << mahasiswa.jurusan
                  << ", Usia: " << mahasiswa.usia << ", IPK: " << mahasiswa.ipk << std::endl;
    }
}

int main() {
    std::string filename = "database.txt";
    std::vector<Mahasiswa> mahasiswas = loadMahasiswa(filename);
    std::sort(mahasiswas.begin(), mahasiswas.end(), compareByNama);
    displayMahasiswa(mahasiswas);
    return 0;
}

