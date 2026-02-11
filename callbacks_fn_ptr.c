#include <stdio.h>

typedef void (*visit_fn)(int value, void *ctx);

void visit_range(int start, int end, visit_fn visitor, void *ctx){
        for(int v = start; v <= end; v++){
                visitor(v, ctx);
        }
}
struct sum_data{
        int total;
};

void add_to_sum(int value, void *ctx){
        struct sum_data *data = ctx;
        data->total += value;
}

int main(void){
        struct sum_data data = {0};

        visit_range(1, 5, add_to_sum, &data);
        printf("Sum from 1 to 5 is %d\n", data.total);

        return 0;
}
