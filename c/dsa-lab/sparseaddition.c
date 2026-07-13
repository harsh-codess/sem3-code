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

                // 0,0 is for the number of rows, cols and numebr of non zero elements.

                // */ 1,0 - rows col   value
                //         0
                //         1  i;   j;  a[i][j];
                //         2
                //          3

                

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
}


void mergesparse(int sparsea[MAX][3], int sparseb[MAX][3], int addedsparse[MAX][3]) { 
    if (sparsea[0][0] == sparseb[0][0] && sparsea[0][1] == sparseb[0][1]) {
    int i = 1;  // walks sparsea's triplets
int j = 1;  // walks sparseb's triplets
int k = 1;  // where to write the next triplet into addedsparse




} else {
    printf("Cannot add: matrices have different dimensions\n");
}
}
