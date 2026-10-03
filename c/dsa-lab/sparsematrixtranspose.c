#include <stdio.h> 


    # define MAX 10

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



void transposematrix() {
    int arr[10][3];
    int k = 1; 

    for(int i = 0; i < arr[0][1]; i++) { 
            

     


    }



}



     
