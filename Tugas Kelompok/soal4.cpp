#include <iostream>

const int MAX_ROWS = 4; // Maximum number of rows in the matrix
const int MAX_COLS = 4; // Maximum number of columns in the matrix

// Function to input a matrix from the user
void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, const std::string& matrixName) {
    std::cout << "Enter values for matrix " << matrixName << " (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter value at position (" << (i + 1) << "," << (j + 1) << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_ROWS][MAX_COLS], const int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, const std::string& matrixName) {
    std::cout << "Matrix " << matrixName << " (" << rows << "x" << cols << "):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];

    // Input matrices
    inputMatrix(matrix1, MAX_ROWS, MAX_COLS, "A");
    inputMatrix(matrix2, MAX_ROWS, MAX_COLS, "B");

    // Add matrices
    addMatrices(matrix1, matrix2, result, MAX_ROWS, MAX_COLS);

    // Display matrices and result
    displayMatrix(matrix1, MAX_ROWS, MAX_COLS, "A");
    displayMatrix(matrix2, MAX_ROWS, MAX_COLS, "B");
    displayMatrix(result, MAX_ROWS, MAX_COLS, "Sum");

    return 0;
}

