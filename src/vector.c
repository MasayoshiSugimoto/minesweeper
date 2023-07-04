#include "vector.h"


void vector_as_string(char* buf, struct Vector v) {
  sprintf(buf, "{x:%d, y:%d}", v.x, v.y); 
}


