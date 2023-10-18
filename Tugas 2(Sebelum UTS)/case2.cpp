#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool isTrue = (a * b) > (c + d);

    if (isTrue) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

