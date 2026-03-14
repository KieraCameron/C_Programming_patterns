#pragma once

#define COMMA() ,

#define EMPTY()
#define EXPAND(...) __VA_ARGS__

#define CONCAT(a, b) a##b
#define XCONCAT(a, b) CONCAT(a, b)

#define STRINGIFY(a) #a
#define XSTRINGIFY(a) STRINGIFY(a)
