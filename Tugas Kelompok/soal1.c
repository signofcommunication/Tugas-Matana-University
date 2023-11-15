#include <stdio.h>

int highest(int arr[]) {
    int length = sizeof(arr) / sizeof(arr[0]);
    int maximum = 0;

    for (int j = 0; j < length; j++) {
        if (arr[j] > maximum) {
            maximum = arr[j];
        }
    }

    return maximum;
}

int main() {
    int res1 = 0, res2 = 0, res3 = 0, res4 = 0, res5 = 0;
    int selected = 0;

    printf("Pemilihan Kepala Daerah MaduraGakure\n");
    printf("====================================\n");
    printf("1. Budi - Susi\n");
    printf("2. Roby - Rini\n");
    printf("3. Rita - Doni\n");
    printf("4. Asep - Joni\n");
    printf("5. Upin - Ipin\n\n");

    for (int i = 0; i < 20; i++) {
        printf("Masukan nomor urut pilihan anda(Pilihan ke - %d) : ", i + 1);
        scanf("%d", &selected);

        switch (selected) {
        case 1:
            res1++;
            break;
        case 2:
            res2++;
            break;
        case 3:
            res3++;
            break;
        case 4:
            res4++;
            break;
        case 5:
            res5++;
            break;
        }

        selected = 0;
    }

    int arrRes[5] = {res1, res2, res3, res4, res5};

    printf("%d\n", highest(arrRes));

    return 0;
}

