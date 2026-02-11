#include <stdio.h>

int add(int a, int b){
        return a+b;
}

int subtract(int a, int b){
        return a-b;
}

int main(void){
        int (*op)(int, int); 
        // pointer to function taking two int parameters and returning int
        
        op = add;
        //op = &add;
        printf("3+4 = %d\n", op(3,4));

        op = subtract;
        printf("7-2=%d\n", op(7, 2));

        return 0;
}
