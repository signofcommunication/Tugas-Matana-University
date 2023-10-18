#include <iostream>
using namespace std;

int main() {
    int d, s, t;
    cin >> d >> s >> t;

    int anggaran_tertinggi, anggaran_terendah, anggaran_tengah;

    // Menentukan anggaran tertinggi
    if (d >= s && d >= t) {
        anggaran_tertinggi = d;
        anggaran_tengah = (s >= t) ? s : t;
        anggaran_terendah = (s < t) ? s : t;
    } else if (s >= d && s >= t) {
        anggaran_tertinggi = s;
        anggaran_tengah = (d >= t) ? d : t;
        anggaran_terendah = (d < t) ? d : t;
    } else {
        anggaran_tertinggi = t;
        anggaran_tengah = (d >= s) ? d : s;
        anggaran_terendah = (d < s) ? d : s;
    }

    // Menampilkan urutan belanja
    if (d == anggaran_tertinggi) {
    	cout << "Daging" << endl;	
	} else if (s == anggaran_tertinggi) {
		cout << "Sayur" << endl;
	} else {
		cout << "Telur" << endl;
	}
        

    if (d == anggaran_tengah) {
    	cout << "Daging" << endl;
	}      
    else if (s == anggaran_tengah) {
    	cout << "Telur" << endl;	
	} else {
    	cout << "Telur" << endl;	
	}

    if (d == anggaran_terendah) {
    	cout << "Daging" << endl;	
	} else if (s == anggaran_terendah) {
    	cout << "Sayur" << endl;	
	} else {
    	cout << "Telur" << endl;
	}
        

    return 0;
}

