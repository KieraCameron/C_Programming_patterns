#include <stdio.h>

typedef int (*operation_fn)(int, int);

int add_ints(int a, int b){
        return a+b;
}

int multiply_ints(int a, int b){
        return a*b;
}

int main(void){
        operation_fn operations[2];

        operations[0] = add_ints;
        operations[1] = multiply_ints;

        int x = 6;
        int y = 7;

        printf("add_ints: %d\n", operations[0](x,y));
        printf("multiply_ints: %d\n", operations[1](x,y));

        return 0;
}

