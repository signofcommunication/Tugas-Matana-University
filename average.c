#include <stdio.h>

int main() {
    const int PRICE_A = 100000;
    const int PRICE_B = 150000;
    const int PRICE_C = 95000;
    int i,j;

    int sales[10][3];
    double commission[10];

    for (i = 0; i < 10; i++) {
        printf("Salesperson %d:\n", i+1);
        for (j = 0; j < 3; j++) {
            char item = 'A' + j;
            printf("  Item %c: ", item);
            scanf("%d", &sales[i][j]);
        }
    }

    for (i = 0; i < 10; i++) {
        int total_sales = sales[i][0]*PRICE_A + sales[i][1]*PRICE_B + sales[i][2]*PRICE_C;
        if (total_sales > 10000000) {
            commission[i] = 0.2 * total_sales;
        } else {
            commission[i] = 0.1 * total_sales;
        }
    }

    printf("Commission for each salesperson:\n");
    for (i = 0; i < 10; i++) {
        printf("Salesperson %d: %.2f\n", i+1, commission[i]);
    }

    double avg_sales[3] = {0};
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) {
            avg_sales[j] += sales[i][j];
        }
    }
    for (j = 0; j < 3; j++) {
        avg_sales[j] /= 10;
    }

    printf("Average sales for each item:\n");
    printf("  Item A: %.1f\n", avg_sales[0]);
    printf("  Item B: %.1f\n", avg_sales[1]);
    printf("  Item C: %.1f\n", avg_sales[2]);

    double total_sales = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) {
            total_sales += sales[i][j] * (j == 0 ? PRICE_A : (j == 1 ? PRICE_B : PRICE_C));
        }
    }
    double avg_sales_all = total_sales / 30;

    printf("Average sales overall: %.1f\n", avg_sales_all);

    return 0;
}
