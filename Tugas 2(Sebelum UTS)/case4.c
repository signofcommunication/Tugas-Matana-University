#include <stdio.h>

int main() {
    int x1, x2, x3;
    scanf("%d %d %d", &x1, &x2, &x3);

    printf("%.3f\n", (float)x1/999);
    printf("%.3f\n", (float)x2/999);
    printf("%.3f\n", (float)x3/999);

    return 0;
}

