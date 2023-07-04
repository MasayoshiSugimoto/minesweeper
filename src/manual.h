#ifndef MANUAL_H
#define MANUAL_H


#include <curses.h>
#include <ncurses.h>
#include "log.h"
#include "window_manager.h"
#include "util.h"


struct Manual {
  int line_offset;
};


void manual_init(struct Manual* manual);
void manual_move_up(struct Manual* manual);
void manual_move_down(struct Manual* manual);
void manual_get_page(struct Manual* manual, const char** buf, size_t length);

#endif
