#include <iostream>
using namespace std;

int main(void) {
	int a,b,res = 0;
	cout << "Input First Number : ";
	cin >> a;
	cout << "Input Second Number : ";
	cin >> b;
	
	for(int n = a; n <= b; n++) {
		res += n;
	}
	cout << res;
}
