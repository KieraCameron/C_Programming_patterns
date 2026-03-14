// Note - no include guard.
#include "basic.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// template paramteers
#if __IDE__
// Provide definitions for IDE.
#define a_PREFIX  prefix
#define a_TYPE    int
#define a_FMT     "%d"
#endif
#ifndef a_PREFIX
#error a_PREFIX is not defined
#endif
#ifndef a_TYPE
#error a_TYPE is not defined
#endif
#ifndef a_FMT
#error a_FMT is not defined
#endif

#define i_MEMB(x)  XCONCAT(a_PREFIX, _vector_##x)
#define i_TYPE     XCONCAT(a_PREFIX, _vector)

struct i_TYPE {
   a_TYPE *elems;
   size_t s;
};

static inline int i_MEMB(push)(struct i_TYPE *self, a_TYPE e) {
    void *pnt = realloc(self->elems, self->s + 1);
    if (!pnt) return -ENOMEM;
    self->elems = pnt;
    self->elems[self->s] = e;
    self->s++;
    return 0;
}

#ifdef a_FMT
static inline void i_MEMB(print)(struct i_TYPE *self) {
    for (size_t i = 0; i < self->s; ++i) {
        if (i != 0) {
            putchar(' ');
        }
        printf(a_FMT, self->elems[i]);
    }
    putchar('\n');
}
#endif

static inline void i_MEMB(free)(struct i_TYPE *self) {
    free(self->elems);
}

#undef a_TYPE
#undef a_PREFIX
#undef a_FMT
#undef i_TYPE
#undef i_MEMB
