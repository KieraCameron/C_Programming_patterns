#include <stdio.h>

int main(void){
        int a = 10;

        int *ptr = &a;
        int **dptr = &ptr;

        printf("Value of a : %d\n", a);
        printf("Value via ptr: %d\n", *ptr);
        printf("Value via dptr: %d\n", **dptr);

        **dptr = 20;

        printf("New value of a: %d\n", a);

        printf("*dptr : %p\n", *dptr);

        printf("ptr : %p\n", ptr);

        return 0;
}
