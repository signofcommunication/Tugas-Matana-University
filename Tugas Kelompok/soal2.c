#include <stdio.h>

int main() {
    const int arraySize = 10;
    int numbers[arraySize];

    printf("Enter 10 integer values:\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int min = numbers[0];
    int max = numbers[0];
    int sum = numbers[0];

    for (int i = 1; i < arraySize; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
        sum += numbers[i];
    }

    double average = (double)sum / arraySize;

    printf("\nResults:\n");
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Average value: %f\n", average);

    return 0;
}

