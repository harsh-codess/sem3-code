#include <stdio.h>

#define MAX 10

void accept_matrix(int a[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter matrix (%d x %d):\n", rows, cols);
            scanf("%d", &a[i][j]);
        }
    }
}

void compact_matrix(int matrix[MAX][MAX], int rows, int cols, int sparse[MAX][3])
{
    int sparsecounter = 1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[sparsecounter][0] = i;
                sparse[sparsecounter][1] = j;
                sparse[sparsecounter][2] = matrix[i][j];
                sparsecounter++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = sparsecounter - 1;
}

void mergesparse(int sparsea[MAX][3], int sparseb[MAX][3], int addedsparse[MAX][3])
{
    if (sparsea[0][0] == sparseb[0][0] && sparsea[0][1] == sparseb[0][1])
    {
        int i = 1; // walks sparsea's triplets
        int j = 1; // walks sparseb's triplets
        int k = 1; // where to write the next triplet into addedsparse

        // MAIN MERGE LOOP — runs as long as both A and B still have triplets left to compare
        while (i <= sparsea[0][2] && j <= sparseb[0][2])
        {
            // CASE 1: A's position comes first (smaller row, or same row + smaller column)
            if (sparsea[i][0] < sparseb[j][0] || (sparsea[i][0] == sparseb[j][0] && sparsea[i][1] < sparseb[j][1]))
            {
                addedsparse[k][0] = sparsea[i][0];
                addedsparse[k][1] = sparsea[i][1];
                addedsparse[k][2] = sparsea[i][2];
                i++;
                k++;
            }
            // CASE 2: B's position comes first (mirror image of Case 1)
            else if (sparsea[i][0] > sparseb[j][0] || (sparsea[i][0] == sparseb[j][0] && sparsea[i][1] > sparseb[j][1]))
            {
                addedsparse[k][0] = sparseb[j][0];
                addedsparse[k][1] = sparseb[j][1];
                addedsparse[k][2] = sparseb[j][2];
                j++;
                k++;
            }
            // CASE 3: TIE — same row AND same column in both A and B
            else
            {
                addedsparse[k][0] = sparsea[i][0];
                addedsparse[k][1] = sparsea[i][1];
                addedsparse[k][2] = sparsea[i][2] + sparseb[j][2];
                i++;
                j++;
                k++;
            }
        }

        // LEFTOVER LOOP #1 — whatever's still left in A gets copied straight over
        while (i <= sparsea[0][2])
        {
            addedsparse[k][0] = sparsea[i][0];
            addedsparse[k][1] = sparsea[i][1];
            addedsparse[k][2] = sparsea[i][2];
            i++;
            k++;
        }

        // LEFTOVER LOOP #2 — whatever's still left in B gets copied straight over
        while (j <= sparseb[0][2])
        {
            addedsparse[k][0] = sparseb[j][0];
            addedsparse[k][1] = sparseb[j][1];
            addedsparse[k][2] = sparseb[j][2];
            j++;
            k++;
        }

        // HEADER — same k-1 trick as compact_matrix
        addedsparse[0][0] = sparsea[0][0];
        addedsparse[0][1] = sparsea[0][1];
        addedsparse[0][2] = k - 1;
    }
    else
    {
        printf("Cannot add: matrices have different dimensions\n");
    }
} // <-- this closing brace was missing, now added: closes mergesparse properly

int main()
{
    int my_matrix[10][10];
    accept_matrix(my_matrix, 3, 3);

    int my_matrixb[10][10];
    accept_matrix(my_matrixb, 3, 3);

    int sparseA[MAX][3];
    int sparseB[MAX][3];

    compact_matrix(my_matrix, 3, 3, sparseA);
    compact_matrix(my_matrixb, 3, 3, sparseB);

    printf("Sparse A:\n");
    for (int i = 0; i <= sparseA[0][2]; i++)
        printf("%d %d %d\n", sparseA[i][0], sparseA[i][1], sparseA[i][2]);

    printf("Sparse B:\n");
    for (int i = 0; i <= sparseB[0][2]; i++)
        printf("%d %d %d\n", sparseB[i][0], sparseB[i][1], sparseB[i][2]);

    int sparseResult[MAX][3];
    mergesparse(sparseA, sparseB, sparseResult);

    printf("Sparse Result (A + B):\n");
    for (int i = 0; i <= sparseResult[0][2]; i++)
        printf("%d %d %d\n", sparseResult[i][0], sparseResult[i][1], sparseResult[i][2]);
}