#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int sum = (B - A + 1) * (A + B) / 2;

    printf("%d\n", sum);

    return 0;
}

