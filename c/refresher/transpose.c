#include <stdio.h>



int main () { 


int a[2][3]; 
int transpose[3][2];


int i, j; 


for(i = 0; i < 2; i++) { 
    for ( j = 0; j < 3; j++) { 
        scanf("%d", &a[i][j]); 

    }

}


for(i = 0; i < 2; i++) { 
    for ( j = 0; j < 3; j++) { 
      transpose[j][i] = a[i][j];
      

    }
   

}



for(i = 0; i < 3; i++) { 
    for (int j = 0; j < 2; j++) { 
        printf("%d", transpose[i][j]);
    }
    printf("\n");
}

return 0;
} 



// #include <stdio.h>

// int main() {
//     int a[2][3];
//     int transpose[3][2];
//     int i, j;

//     for (i = 0; i < 2; i++)
//         for (j = 0; j < 3; j++)
//             scanf("%d", &a[i][j]);

//     for (i = 0; i < 2; i++)
//         for (j = 0; j < 3; j++)
//             transpose[j][i] = a[i][j];

//     for (i = 0; i < 3; i++) {
//         for (j = 0; j < 2; j++)
//             printf("%d ", transpose[i][j]);
//         printf("\n");
//     }

//     return 0;
// }

