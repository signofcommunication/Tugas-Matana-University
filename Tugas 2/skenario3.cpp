#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double A, B;
    cin >> A >> B;

    double discount = ((A - B) / A) * 100.0; 
    
    cout << fixed << setprecision(2) << discount << "%" << endl;

    return 0;
}

