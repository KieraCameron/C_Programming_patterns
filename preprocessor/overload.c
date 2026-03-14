#include <stdio.h>

int foo(int a, int b, int c, int d);

// Overload without 0th case. Default argumenst can be provided for b, c, d.
#define FOO_1(a)           foo(a, 1, 2, 3)
#define FOO_2(a, b)        foo(a, b, 2, 3)
#define FOO_3(a, b, c)     foo(a, b, c, 3)
#define FOO_4(a, b, c, d)  foo(a, b, c, d)
#define FOO_N(_4,_3,_2,_1,N,...)  FOO##N
#define FOO(...)  FOO_N(##__VA_ARGS__, _4,_3,_2,_1)(__VA_ARGS__)

int bar(int a, int b, int c, int d);

// Overload with a zero arguments case.
#define BAR_0()            bar(0, 1, 2, 3)
#define BAR_1(a)           bar(a, 1, 2, 3)
#define BAR_2(a, b)        bar(a, b, 2, 3)
#define BAR_3(a, b, c)     bar(a, b, c, 3)
#define BAR_4(a, b, c, d)  bar(a, b, c, d)
// What I call "overload resolving macro".
#define BAR_N(_4,_3,_2,_1,_0,N,...)  BAR##N
// Calling "overload resolving macro" to choose proper overload condidate.
#define BAR(...)  BAR_N(_0 __VA_OPT__(,) __VA_ARGS__, _4,_3,_2,_1)(__VA_ARGS__)

int main(void) {
  BAR(5); // calls bar(5, 1, 2, 3);
}
