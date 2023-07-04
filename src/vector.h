#ifndef VECTOR_H
#define VECTOR_H


#include <stdio.h>


struct Vector {
  int x;
  int y;
};


void vector_as_string(char* buf, struct Vector v);


#endif
