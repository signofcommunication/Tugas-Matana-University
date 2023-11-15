#include <iostream>
using namespace std;

int highest(int arr[]) {
	int length = sizeof(arr) / sizeof(arr[0]);
	int maximum = 0;
	
	for(int j = 0; j < length; j++) {
			if(arr[j] > maximum) {
				maximum = arr[j];
			}
	}
	
	return maximum;
}

int main() {
	int res1 = 0,res2 = 0,res3 = 0,res4 = 0,res5 = 0;
	int selected = 0;
	
	cout << "Pemilihan Kepala Daerah MaduraGakure" << endl;
	cout << "====================================" << endl;
	cout << "1. Budi - Susi" << endl;
	cout << "2. Roby - Rini" << endl;
	cout << "3. Rita - Doni" << endl;
	cout << "4. Asep - Joni" << endl;
	cout << "5. Upin - Ipin" << endl;
	cout << endl;
	
	for(int i = 0; i < 20; i++) {
		cout << "Masukan nomor urut pilihan anda(Pilihan ke - " << i + 1 << ") : ";
		cin >> selected;
		
		switch(selected) {
			case 1:
				res1++;
			break;
			case 2:
				res2++;
			break;
			case 3:
				res3++;
			break;
			case 4:
				res4++;
			break;
			case 5:
				res5++;
			break;
		}
		
		selected = 0;
	}
	int arrRes[5] = {res1,res2,res3,res4,res5};
	
	cout << highest(arrRes);
	
	return 0;
}
