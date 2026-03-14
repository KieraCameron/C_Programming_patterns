#include "basic.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define DEFINE_VECTOR(N, T, FMT) \
  \
struct XCONCAT(N, _vector) { \
   T *elems; \
   size_t s; \
}; \
  \
static inline int XCONCAT(N, _vector_push)(struct XCONCAT(N, _vector) *this, T e) {  \
    void *pnt = realloc(this->elems, this->s + 1);  \
    if (!pnt) return -ENOMEM;  \
    this->elems = pnt;  \
    this->elems[this->s] = e;  \
    this->s++;  \
    return 0;  \
}  \
  \
static inline void XCONCAT(N, _vector_print)(struct XCONCAT(N, _vector) *this) {  \
    for (size_t i = 0; i < this->s; ++i) {  \
        if (i != 0) {  \
            putchar(' ');  \
        }  \
        printf(FMT, this->elems[i]);  \
    }  \
    putchar('\n');  \
}  \
  \
static inline void XCONCAT(N, _vector_free)(struct XCONCAT(N, _vector) *this) {  \
    free(this->elems);  \
}  \
  \
/* */

DEFINE_VECTOR(int, int, "%d")
DEFINE_VECTOR(double, double, "%.1f")

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
