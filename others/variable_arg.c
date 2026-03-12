#include <stdarg.h>
#include <stdio.h>

int min(int arg_count, ...){
        int i; 
        int min, a;
        
        //va_list is  a type to hold information about variable arguments
        va_list ap;

        //va_start must be called before accessing variable argument list
        va_start(ap, arg_count);


        //va_arg is a macro
        //Initiallize min as first argument in list
        min = va_arg(ap, int);

        for(i=2; i<= arg_count; i++)
                if((a = va_arg(ap,int))< min)
                        min = a;

        va_end(ap);
        return min;
}

int main(){
        int count = 5;
        printf("Minimum value is %d ", min(count, 12, 67, 6, 7, 100));
        return 0;
}
