#ifndef UTIL_H
#define UTIL_H


#include <time.h>
#include <stdint.h>


#define array_size(arr) sizeof(arr) / sizeof(arr[0])

#define boolean_as_string(b) b ? "true" : "false"

#define imin(a, b) a < b ? a : b
#define imax(a, b) a < b ? b : a


uint64_t get_current_millisecond();


#endif

