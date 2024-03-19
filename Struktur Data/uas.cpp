#include <iostream>
#include <string>
#include "read.h"
#include "create.h"
#include "update.h"
#include "delete.h"
#include "read_single.h"
#include "sort.h"
using namespace std;

int main() {
	string name;
	string major;
	string age;
	string gpa;
	int delete_id;
	int line_number;
	int choice;
	int id_mahasiswa;
	
	do {
		cout << "Menu:" << endl;
        cout << "1. Tambahkan Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Perbarui Data Mahasiswa" << endl;
        cout << "4. Cari Data Mahasiswa berdasarkan ID" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "6. Tampilkan Semua Data Berdasarkan Nama(Sort)" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;
        
        switch(choice) {
        	case 1:
        		cout << "Masukan Nama Mahasiswa: ";
				cin >> name;
				
				cout << "Masukan Jurusan Mahasiswa: ";
				cin >> major;
				
				cout << "Masukan Umur Mahasiswa: ";
				cin >> age;
				
				cout << "Masukan IPK Mahasiswa: ";
				cin >> gpa;
				
				createNew(name,major,age,gpa);
        		break;
        	case 2:
        		cout << "Berikan ID Mahasiswa yang ingin dihapus: ";
        		cin >> delete_id;
        		deleteData(delete_id);
        		break;
        	case 3:
        		cout << "Masukan ID untuk mengupdate data: ";
        		cin >> line_number;
        		updateData(line_number);
        		break;
        	case 4:
        		cout << "Masukan ID untuk mendapatkan data mahasiswa: ";
        		cin >> id_mahasiswa;
        		read_single(id_mahasiswa);
        		break;
        	case 5:
        		readFile("database.txt");
        		break;
        	case 6:
        		sortData("database.txt");
        		break;
			case 7:
        		cout << "Terima Kasih! Program Berakhir.";
        		break;
        	default:
        		cout << "Pilihan tidak valid. Silahkan coba lagi.";
        		break;
		}
	} while(choice != 8);
	
	return 0;
}
