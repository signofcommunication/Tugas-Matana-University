#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    cout << fixed << setprecision(3) << (double)x1/999 << endl;
    cout << fixed << setprecision(3) << (double)x2/999 << endl;
    cout << fixed << setprecision(3) << (double)x3/999 << endl;

    return 0;
}
