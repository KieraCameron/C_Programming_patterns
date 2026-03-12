#include <stdio.h>

typedef struct{
        int _pc;
        int a;
        int b;
        int n;
} fib_frame;

#define generator_init() switch (f->_pc) { case 0:
#define generator_done(R) } return R
#define yield(R) f->_pc = __LINE__; return R; case __LINE__:

int fib(fib_frame *f) {
        generator_init();
        f->a = 0;
        f->b = 1;
        f->n = 1;
        while(1){
                yield(f->a);
                f->a = f->b;
                f->b = f->n;
                f->n = f->a+f->b;
        }
        generator_done(-1);
}

int main(){
        fib_frame f = {};
        for(int i = 0; i<15; i++){
                printf("%d \n", fib(&f));
        }
        return 0;
}
