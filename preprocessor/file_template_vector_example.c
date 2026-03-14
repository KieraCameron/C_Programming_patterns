// main.c
#define a_PREFIX int
#define a_TYPE int
#define a_FMT "%d"
#include "file_template_vector.h"

#define a_PREFIX double
#define a_TYPE double
#define a_FMT "%.1f"
#include "file_template_vector.h"

int main() {
    struct int_vector ia = {0};
    int_vector_push(&ia, 1);
    int_vector_push(&ia, 2);
    int_vector_print(&ia);
    int_vector_free(&ia);
    //
    struct double_vector da = {0};
    double_vector_push(&da, 1.5);
    double_vector_push(&da, 2.5);
    double_vector_print(&da);
    double_vector_free(&da);
}
