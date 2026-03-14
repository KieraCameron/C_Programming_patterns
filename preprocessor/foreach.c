#include "basic.h"
#include <stdio.h>

#define FOREACH_1(f, sep, a)       f(a)
#define FOREACH_2(f, sep, a, ...)  f(a) sep() FOREACH_1(f, sep, __VA_ARGS__)
#define FOREACH_3(f, sep, a, ...)  f(a) sep() FOREACH_2(f, sep, __VA_ARGS__)
#define FOREACH_4(f, sep, a, ...)  f(a) sep() FOREACH_3(f, sep, __VA_ARGS__)
// Add more cases _5 _6 ...
#define FOREACH_N(_4,_3,_2,_1,N,...)  FOREACH##N
#define FOREACH(f, sep, ...)  FOREACH_N(__VA_ARGS__,_4,_3,_2,_1)(f, sep, __VA_ARGS__)

// Example usage to stringify enum elements.
#define ELEMS  CAR, BIKE, PLANE

enum things {
  FOREACH(EXPAND, COMMA, ELEMS)
};

const char *thing_to_string[] = {
  FOREACH(XSTRINGIFY, COMMA, ELEMS)
};

int main(void) {
  printf("Macro CAR is %s\n", thing_to_string[CAR]);
  printf("Macro BIKE is %s\n", thing_to_string[BIKE]);
}

