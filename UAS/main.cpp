#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<pair<string, int>>> arrayOfArrays;
vector<pair<string, int>> innerArray;

string lastWord(const string& text) {
	int i = text.length() - 1;
	
	if(isspace(text[i])) {
		while(isspace(text[i])) {
			i--;
		}
	}
	
	while(i != 0 && !isspace(text[i])) {
		--i;
	}
	
	string lastword = text.substr(i + 1);
	return lastword;
}

int convertStringToInt(string word) {
	stringstream ss;
	int num;
	
	ss << word;
	ss >> num;
	return num;
}

int stokObat(int line_number) {
  ifstream file;
  int result;
  
  if (line_number <= 0) {
    cout << "Line number must be >= 1" << endl;
    return 1;
  }
  
  file.open("data.txt");
  
  if (file.fail()) {
    cout << "File failed to open." << endl;
    return 1; 
  }
  
  int current_line = 0;
  string line;
  
  while (!file.eof()) {
    current_line++;

    getline(file, line);

    if (current_line == line_number) break;
  }
  
  if (current_line < line_number) {
    cout << "Line not found!" << endl;
    cout << "File contains " << current_line;
    cout << " lines total." << endl;
  } else {
    result = convertStringToInt(lastWord(line));
  }
  
  
  file.close();

  return result; 
}

int edit(int line_number,string text) {
  fstream read_file;
  
  read_file.open("data.txt");
  
  if (read_file.fail()) {
    cout << "Error opening file." << endl;

    return 1;
  }
  
  vector<string> lines;
  string line;
  
  while (getline(read_file, line))
    lines.push_back(line);
  
  read_file.close();
  
  if (line_number > lines.size()) {
    cout << "Line " << line_number;
    cout << " not in file." << endl;
    
    cout << "File has " << lines.size();
    cout << " lines." << endl;

    return 1;
  }
  
  ofstream write_file;
  
  write_file.open("data.txt");
  
  if (write_file.fail()) {
    cout << "Error opening file." << endl;
    return 1;
  }
  
  line_number--;

  for (int i = 0; i < lines.size(); i++) {
    if (i != line_number)
      write_file << lines[i] << endl;
    else 
      write_file << text << endl; 
  }
  
  write_file.close();
  return 0;
}

void appendArray(string nama_obat,int jumlah_obat) {
    pair<string, int> userPair = make_pair(nama_obat, jumlah_obat);

    innerArray.push_back(userPair);

    arrayOfArrays.push_back(innerArray);

    for (const auto& innerVector : arrayOfArrays) {
        for (const auto& element : innerVector) {
            cout << "String: " << element.first << ", Integer: " << element.second << endl;
        }
    }
}

int main() {
	cout << "====================================" << endl;
	cout << "|  NO  |  Obat  |  Stok  |  Harga  |" << endl;
	cout << "------------------------------------" << endl;
	cout << "|  1.  |  Panadol  | "<<  stokObat(1) << " |Rp.20.000 |" << endl;
	cout << "|  2.  |  Bodrex  | " <<  stokObat(2) << " |  Rp.5.000 |" << endl;
	cout << "|  3.  |  Antimo  | " <<  stokObat(3) <<" |  Rp.7.000 |" << endl;
	cout << "------------------------------------" << endl;
	
	int PANADOL = 20000,BODREX = 5000,ANTIMO = 7000;
	int STOK_PANADOL = stokObat(1),STOK_BODREX = stokObat(2), STOK_ANTIMO = stokObat(3);
	int TOTAL_PEMBAYARAN = 0,KEMBALIAN,UANG_PEMBAYARAN;
	int kode_obat,jumlah_obat;
	bool state = true;
	int pilihan;
	
	while(state) {
		cout << "Masukan Nama Kode Obat : ";
		cin >> kode_obat;
		cout << "Jumlah obat yang diinginkan : ";
		cin >> jumlah_obat;

		switch(kode_obat) {
			case 1: {
				if(STOK_PANADOL == 0) {
					cout << "Stok Obat Panadol habis!";
					return 1;
				}
				
				TOTAL_PEMBAYARAN = PANADOL * jumlah_obat;
				STOK_PANADOL = STOK_PANADOL - jumlah_obat;
				string stok_baru = to_string(STOK_PANADOL);
				string text_obat = "STOK_PANADOL " + stok_baru;
				edit(1,text_obat);
				appendArray("Panadol",jumlah_obat);
			}
			break;
			case 2:{
				if(STOK_BODREX == 0) {
					cout << "Stok Obat Bodrex habis!";
					return 1;
				}
					
				TOTAL_PEMBAYARAN = BODREX * jumlah_obat;
				STOK_BODREX = STOK_BODREX - jumlah_obat;
				string stok_baru_2 = to_string(STOK_BODREX);
				string text_obat_2 = "STOK_BODREX " + stok_baru_2;
				edit(2,text_obat_2);	
				appendArray("Bodrex",jumlah_obat);
			}
			break;
			case 3: {
				if(STOK_ANTIMO == 0) {
					cout << "Stok Obat Antimo habis!";
					return 1;
				}
				
				TOTAL_PEMBAYARAN = ANTIMO * jumlah_obat;
				STOK_ANTIMO = STOK_ANTIMO - jumlah_obat;
				string stok_baru_3 = to_string(STOK_ANTIMO);
				string text_obat_3 = "STOK_ANTIMO " + stok_baru_3;
				edit(3,text_obat_3);
				appendArray("Antimo",jumlah_obat);	
			}
			break;
			default: 
				cout << "Tidak ada opsi " << kode_obat << " ngentot! Pilih kode yang lain lagi!!" << endl;
				continue;
			
		}
		
		cout << "Masukan uang pembayaran : ";
		cin >> UANG_PEMBAYARAN;
		
		if(UANG_PEMBAYARAN < TOTAL_PEMBAYARAN) {
			cout << "STATUS : Pembayaran GAGAL!!" << endl;
			cout << "Uang pembayaran lebih kecil daripada total pembayaran!!!" << endl;
			cout << "Masukan uang pembayaran kembali dengan benar : ";
			cin >> UANG_PEMBAYARAN;
		}
		
		cout << "Kembalian : Rp."<< UANG_PEMBAYARAN - TOTAL_PEMBAYARAN << endl;
		cout << "STATUS : Pembayaran BERHASIL!!" << endl;
		
		// Show History right here
		
		cout << "Apakah mau belanja lagi??(1: Iya, 0: Tidak): ";
		cin >> pilihan;
		
		if(pilihan == 1) {
			continue;
		} else {
			state = false;
		}
	}
	
	return 0;
}
