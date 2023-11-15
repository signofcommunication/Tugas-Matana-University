#include <iostream>
using namespace std;

const int MAX_ROWS_A = 4;
const int MAX_COLS_A = 4;
const int MAX_ROWS_B = 4;
const int MAX_COLS_B = 4;

void inputMatrix(int matrix[MAX_ROWS_A][MAX_COLS_A], int rows, int cols, const string& matrixName) {
    cout << "Enter values for matrix " << matrixName << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter value at position (" << (i + 1) << "," << (j + 1) << "): ";
            cin >> matrix[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrixA[MAX_ROWS_A][MAX_COLS_A], const int matrixB[MAX_ROWS_B][MAX_COLS_B], int result[MAX_ROWS_A][MAX_COLS_B]) {
    for (int i = 0; i < MAX_ROWS_A; ++i) {
        for (int j = 0; j < MAX_COLS_B; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < MAX_COLS_A; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void displayMatrix(const int matrix[MAX_ROWS_A][MAX_COLS_B], int rows, int cols, const std::string& matrixName) {
    cout << "Matrix " << matrixName << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrixA[MAX_ROWS_A][MAX_COLS_A];
    int matrixB[MAX_ROWS_B][MAX_COLS_B];
    int result[MAX_ROWS_A][MAX_COLS_B];

    // Input matrices
    inputMatrix(matrixA, MAX_ROWS_A, MAX_COLS_A, "A");
    inputMatrix(matrixB, MAX_ROWS_B, MAX_COLS_B, "B");

    // Multiply matrices
    multiplyMatrices(matrixA, matrixB, result);

    // Display matrices and result
    displayMatrix(matrixA, MAX_ROWS_A, MAX_COLS_A, "A");
    displayMatrix(matrixB, MAX_ROWS_B, MAX_COLS_B, "B");
    displayMatrix(result, MAX_ROWS_A, MAX_COLS_B, "Product");

    return 0;
}

