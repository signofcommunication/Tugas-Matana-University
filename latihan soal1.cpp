#include <iostream>
using namespace std;

bool canReach(int A, int B) {
    while (A != B && A > 1) {
        if (A > B) {
            if (A % 2 == 0) {
                A /= 2;
            } else {
                if ((A - 1) % 3 == 0) {
                    A = (A - 1) / 3;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
    return (A == B);
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        int A, B;
        cin >> A >> B;

        
        cout << "Case #" << i << ": " << (canReach(A, B) ? "YES" : "NO") << endl;
    }

    return 0;
}

