#ifndef TERMINAL_H
#define TERMINAL_H


#include <term.h>
#include <curses.h>
#include <ncurses.h>
#include "vector.h"
#include <stdlib.h>
#include "log.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


struct Terminal {
  int width;
  int height;
};


void terminal_init(struct Terminal* terminal);
struct Vector terminal_center(struct Terminal* terminal);
struct Vector term_get_size(void);


#endif
