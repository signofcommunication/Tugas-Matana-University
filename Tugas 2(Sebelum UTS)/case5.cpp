#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // First square
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "#";
        }
        cout << endl;
    }
    cout << endl;

    // Second square
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i/K)%2 == 0) {
                cout << ".";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Third square
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((j/K)%2 == 0) {
                cout << ".";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }

    return 0;
}
