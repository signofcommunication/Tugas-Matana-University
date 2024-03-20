#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    int id;
    string nama;
    string jurusan;
    int usia;
    double ipk;
};

// Fungsi untuk membandingkan dua mahasiswa berdasarkan nama (untuk digunakan dalam sort)
// Fungsi untuk membandingkan dua mahasiswa berdasarkan nama (untuk digunakan dalam sort)
bool compareByNama(const Mahasiswa& a, const Mahasiswa& b) {
    // Mengambil inisial dari nama
    char initialA = toupper(a.nama[0]);
    char initialB = toupper(b.nama[0]);
    
    // Jika inisial sama, bandingkan nama secara lengkap
    if (initialA == initialB) {
        return a.nama < b.nama;
    }
    
    // Jika inisial berbeda, urutkan berdasarkan inisial
    return initialA < initialB;
}


// Fungsi untuk memuat data dari file
// Fungsi untuk memuat data dari file
vector<Mahasiswa> loadMahasiswa(const string& filename) {
	vector<Mahasiswa> mahasiswas;
	ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string token;
            Mahasiswa mahasiswa;
            int tokenCount = 0;
            while (getline(iss, token, ',')) {
                tokenCount++;
                istringstream tokenStream(token);
                switch (tokenCount) {
                    case 1:
                        tokenStream >> mahasiswa.id;
                        break;
                    case 2:
                        getline(tokenStream, mahasiswa.nama, '"');
                        getline(tokenStream, mahasiswa.nama, '"');
                        break;
                    case 3:
                        getline(tokenStream, mahasiswa.jurusan, '"');
                        getline(tokenStream, mahasiswa.jurusan, '"');
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
        cerr << "Gagal membuka file: " << filename << endl;
    }
    return mahasiswas;
}


// Fungsi untuk menampilkan data mahasiswa
void displayMahasiswa(const vector<Mahasiswa>& mahasiswas) {
    for (const auto& mahasiswa : mahasiswas) {
        cout << "ID: " << mahasiswa.id << ", Nama: " << mahasiswa.nama << ", Jurusan: " << mahasiswa.jurusan
                  << ", Usia: " << mahasiswa.usia << ", IPK: " << mahasiswa.ipk << endl;
    }
}

int main() {
    string filename = "database.txt";
    vector<Mahasiswa> mahasiswas = loadMahasiswa(filename);
    sort(mahasiswas.begin(), mahasiswas.end(), compareByNama);
    displayMahasiswa(mahasiswas);
    return 0;
}
