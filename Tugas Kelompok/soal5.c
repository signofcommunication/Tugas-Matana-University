#include <stdio.h>

#define MAX_ROWS_A 4
#define MAX_COLS_A 4
#define MAX_ROWS_B 4
#define MAX_COLS_B 4

void inputMatrix(int matrix[MAX_ROWS_A][MAX_COLS_A], int rows, int cols, const char* matrixName) {
    int i,j = 0;
	printf("Enter values for matrix %s (%dx%d):\n", matrixName, rows, cols);
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("Enter value at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrixA[MAX_ROWS_A][MAX_COLS_A], const int matrixB[MAX_ROWS_B][MAX_COLS_B], int result[MAX_ROWS_A][MAX_COLS_B]) {
    int j,k,i = 0;
	for (i = 0; i < MAX_ROWS_A; ++i) {
        for (j = 0; j < MAX_COLS_B; ++j) {
            result[i][j] = 0;
            for (k = 0; k < MAX_COLS_A; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void displayMatrix(const int matrix[MAX_ROWS_A][MAX_COLS_B], int rows, int cols, const char* matrixName) {
	int i,j = 0;
    printf("Matrix %s (%dx%d):\n", matrixName, rows, cols);
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA[MAX_ROWS_A][MAX_COLS_A];
    int matrixB[MAX_ROWS_B][MAX_COLS_B];
    int result[MAX_ROWS_A][MAX_COLS_B];

    inputMatrix(matrixA, MAX_ROWS_A, MAX_COLS_A, "A");
    inputMatrix(matrixB, MAX_ROWS_B, MAX_COLS_B, "B");

    multiplyMatrices(matrixA, matrixB, result);

    displayMatrix(matrixA, MAX_ROWS_A, MAX_COLS_A, "A");
    displayMatrix(matrixB, MAX_ROWS_B, MAX_COLS_B, "B");
    displayMatrix(result, MAX_ROWS_A, MAX_COLS_B, "Product");

    return 0;
}

