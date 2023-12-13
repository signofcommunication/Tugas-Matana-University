#include <iostream>
using namespace std;

int main() {
	cout << "====================================" << endl;
	cout << "|  NO  |  Obat  |  Stok  |  Harga  |" << endl;
	cout << "------------------------------------" << endl;
	cout << "|  1.  |  Panadol  |  5 |Rp.20.000 |" << endl;
	cout << "|  2.  |  Bodrex  |  3 |  Rp.5.000 |" << endl;
	cout << "|  3.  |  Antimo  |  4 |  Rp.7.000 |" << endl;
	cout << "------------------------------------" << endl;
	
	int PANADOL = 20000,BODREX = 5000,ANTIMO = 7000;
	int STOK_PANADOL = 5,STOK_BODREX = 2, STOK_ANTIMO = 3;
	int TOTAL_PEMBAYARAN = 0,KEMBALIAN,UANG_PEMBAYARAN;
	int kode_obat,jumlah_obat;
	bool state = true;
	
	while(state) {
		cout << "Masukan Nama Kode Obat : ";
		cin >> kode_obat;
		cout << "Jumlah obat yang diinginkan : ";
		cin >> jumlah_obat;

		switch(kode_obat) {
			case 1:
				if(STOK_PANADOL == 0) {
					cout << "Stok Obat Panadol habis!";
				}
				
				TOTAL_PEMBAYARAN = PANADOL * jumlah_obat;
			break;
			case 2:
				if(STOK_BODREX == 0) {
					cout << "Stok Obat Bodrex habis!";
				}
				
				TOTAL_PEMBAYARAN = BODREX * jumlah_obat;
			break;
			case 3:
				if(STOK_ANTIMO == 0) {
					cout << "Stok Obat Antimo habis!";
				}
				
				TOTAL_PEMBAYARAN = ANTIMO * jumlah_obat;
			break;
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
		cout << "STATUS : Pembayaran BERHASIL!!";
		
		state = false;
	}
	
	
	return 0;
}
