#include <stdio.h>

int main() {
    int i,T;
    scanf("%d", &T);

    for(i = 1; i <= T; i++) {
        int N, a, b, c;
        scanf("%d %d %d %d", &N, &a, &b, &c);

        int x;  // Banyaknya baris pada kelompok kiri

        // Mencari x yang memenuhi konfigurasi ideal
        for (x = 0; x <= N; x++) {
            int left_seats = x * a;
            int middle_seats = (x + 1) * b;
            int right_seats = (x + 2) * c;
            int total_seats = left_seats + middle_seats + right_seats;

            if (total_seats == N) {
                printf("Case #%d: %d\n", i, x);
                break;
            }
        }

        if (x > N) {
            printf("Case #%d: -1\n", i);
        }
    }

    return 0;
}
