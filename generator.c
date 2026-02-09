#include <stdio.h>

typedef struct{
        int _pc;
        int a;
        int b;
}fib_frame;

int fib_next(fib_frame *f){

        switch(f->_pc){
                case 0: goto start;
                case 1: goto resume_1;
        }
        start:
        f->a = 0;
        f->b = 1;

        while(1){
                f->_pc = 1;
                return f->a;

                resume_1:
                int next = f->a + f->b;
                f->a = f->b;
                f->b = next;
        }
}

int main(){
        fib_frame f = {0};
        for (int i = 0; i<10; i++){
                printf("%d ", fib_next(&f));
        }
        return 0;
}

