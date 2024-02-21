#include <iostream>
#include <string>
using namespace std;

struct DataMahasiswa {
	string NIM;
	string nama;
	double tugas;
	int uts;
	int uas;
};

int main() {
	const int SIZE = 3;
	DataMahasiswa datamahasiswa[SIZE];
	
	datamahasiswa[0].NIM = "20235520001";
	datamahasiswa[0].nama = "Ezra Cristiano";
	datamahasiswa[0].tugas = 3.52;
	datamahasiswa[0].uts = 90;
	datamahasiswa[0].uas = 89;
	
	datamahasiswa[1].NIM = "20235520002";
	datamahasiswa[1].nama = "Jeriko Seo";
	datamahasiswa[1].tugas = 4.0;
	datamahasiswa[1].uts = 30;
	datamahasiswa[1].uas = 59;
	
	datamahasiswa[2].NIM = "20235520001";
	datamahasiswa[2].nama = "Bryan Simarjembut";
	datamahasiswa[2].tugas = 3.52;
	datamahasiswa[2].uts = 90;
	datamahasiswa[2].uas = 89;
	
	for(int i = 0; i < SIZE; i++) {
		cout << "NIM: " << datamahasiswa[i].NIM << endl;
		cout << "Nama: " << datamahasiswa[i].nama << endl;
		cout << "Tugas: " << datamahasiswa[i].tugas << endl;
		cout << "Nilai UTS: " << datamahasiswa[i].uts << endl;
		cout << "Nilai UAS: " << datamahasiswa[i].uas << endl;
		cout << endl;
	}
	return 0;
}
