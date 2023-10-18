#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, a, b, c;
        cin >> N >> a >> b >> c;

        // Jumlah baris kiri, tengah, dan kanan
        int x = -1;
        for (int i = 0; i <= N; i++) {
            if ((i + 1) * a + (i + 2) * b + i * c == N) {
                x = i;
                break;
            }
        }

        if (x == -1) {
            cout << "Case #" << t << ": -1" << endl;
        } else {
            cout << "Case #" << t << ": " << x << endl;
        }
    }

    return 0;
}

