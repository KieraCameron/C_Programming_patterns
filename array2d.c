#include <stdio.h>

// 2d array implmentation
//


int main(){
        int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // the above two implementation will lead to same declaration;
        
        int i,j;
        for(i =0; i<3; i++){
                for(j =0; j<3; j++){
                        printf("%3d", matrix[i][j]);
                }
                printf("\n");
        }
        return 0;
}
