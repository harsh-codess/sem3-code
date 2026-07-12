/*
 * Experiment 1 — Matrix operations
 * Write a C program to compute:
 *   a) Addition of two matrices
 *   b) Subtraction of two matrices
 *   c) Multiplication of two matrices
 *   d) Transpose of a matrix
 *
 * Boilerplate (input/output/menu) is done for you below.
 * Fill in the TODOs yourself — that's the actual DSA content of this experiment.
 */

#include <stdio.h>

#define MAX 10

void inputMatrix(int m[MAX][MAX], int rows, int cols) {
    printf("Enter %d elements (row by row):\n", rows * cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &m[i][j]);
}

void printMatrix(int m[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

// TODO: fill result[i][j] = a[i][j] + b[i][j] for every cell
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {

}

// TODO: fill result[i][j] = a[i][j] - b[i][j] for every cell
void subMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {

}

// TODO: standard matrix multiplication — result is (rowsA x colsB), inner dimension is colsA (== rowsB)
void multMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {

}

// TODO: result[j][i] = m[i][j] — rows become columns
void transposeMatrix(int m[MAX][MAX], int result[MAX][MAX], int rows, int cols) {

}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows, cols;
    int choice;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Matrix A:\n");
    inputMatrix(a, rows, cols);
    printf("Matrix B:\n");
    inputMatrix(b, rows, cols);

    printf("\n1. Add  2. Subtract  3. Multiply  4. Transpose (of A)\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrix(a, b, result, rows, cols);
            printMatrix(result, rows, cols);
            break;
        case 2:
            subMatrix(a, b, result, rows, cols);
            printMatrix(result, rows, cols);
            break;
        case 3:
            // NOTE: multiplication needs colsA == rowsB — this simple menu assumes square matrices for now
            multMatrix(a, b, result, rows, cols, cols);
            printMatrix(result, rows, cols);
            break;
        case 4:
            transposeMatrix(a, result, rows, cols);
            printMatrix(result, cols, rows);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
