#include <stdio.h>

int main() {
    int a, b, c, d;

    // Membaca input a, b, c, dan d
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Menghitung hasil operasi pada ruas kiri dan ruas kanan
    int left_result = (a * b) / (c + d);
    int right_result = a * (b / (c + d));

    // Memeriksa apakah hasil ruas kiri lebih besar dari ruas kanan
    if (left_result > right_result) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

