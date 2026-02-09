#include <stdio.h>

// standard declaration
// datatype array_name[size1][size2][size3];

int main(){
        int array[2][3][4] = {
                    {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
        };


        for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                        for(int k = 0; k < 4; k++){
                                printf("%4d", array[i][j][k]);
                        }
                        printf("\n");
                }
                printf("\n\n");
        }
        return 0;
}
