#include <stdio.h> 


int main() { 
            //rows
    int arr[2][3] = {{ 1, 2, 3},{4,5,6}};
               //coloumns


        // how to display -> 


        for(int i = 0; i < 2; i++ ) 
        { 

            for(int j = 0; j < 3; j++)
             { 
                    printf("values : %d\n", arr[i][j]);


            }

        }



    return 0; 

}
