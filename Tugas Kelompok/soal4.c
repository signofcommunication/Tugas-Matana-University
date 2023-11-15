#include <stdio.h>

#define MAX_ROWS 4
#define MAX_COLS 4

void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, const char* matrixName) {
    int i,j = 0;
	printf("Enter values for matrix %s (%dx%d):\n", matrixName, rows, cols);
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("Enter value at position (%d,%d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(const int matrix1[MAX_ROWS][MAX_COLS], const int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i,j = 0;
	for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void displayMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, const char* matrixName) {
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
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];

    inputMatrix(matrix1, MAX_ROWS, MAX_COLS, "A");
    inputMatrix(matrix2, MAX_ROWS, MAX_COLS, "B");

    addMatrices(matrix1, matrix2, result, MAX_ROWS, MAX_COLS);

    displayMatrix(matrix1, MAX_ROWS, MAX_COLS, "A");
    displayMatrix(matrix2, MAX_ROWS, MAX_COLS, "B");
    displayMatrix(result, MAX_ROWS, MAX_COLS, "Sum");

    return 0;
}

