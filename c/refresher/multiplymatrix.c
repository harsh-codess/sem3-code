#include <stdio.h>

int main()
{
#define MAX 10

    int a[MAX][MAX];
    int arows, acoloumns;
    int brows, bcoloumns;
    int b[MAX][MAX];

    printf("enter number of rows and coloumns :");
    scanf("%d %d", &arows, &acoloumns);

    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < acoloumns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("enter number of rows and coloumns of second matrix:");
    scanf("%d %d", &brows, &bcoloumns);

    for (int i = 0; i < brows; i++)
    {
        for (int j = 0; j < bcoloumns; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    int product[MAX][MAX];
    int sum = 0;


    for(int i = 0; i<arows; i++) { 
        for (int j = 0; j<bcoloumns; j++) { 
            for (int k = 0; k<brows; k++) { 
                sum += a[i][k] * b[k][j];
            }
        }
    }



}