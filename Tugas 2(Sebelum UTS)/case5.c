#include <stdio.h>

int main() {
    int i,j,N, K;
    scanf("%d %d", &N, &K);

    // First square
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");

    // Second square
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((i/K) % 2 == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");

    // Third square
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((j/K) % 2 == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}

