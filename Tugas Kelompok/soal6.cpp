#include <iostream>
using namespace std;

int main() {
	int A[3][4]={1, 3, 2, 4, 5, 7, 6, 8, 9,11, 12 };
	int B[3][3]={{1, 2}, {3, 4, 5} ,{ 7 }};
	
	cout << A[1][1] << endl;
	cout << B[2][2] << endl;
	cout << A[2][3] << endl;
	cout << B[0][1] << endl;
	cout << A[0][2] << endl; 
	
	
	return 0;
}
