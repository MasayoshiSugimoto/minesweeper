#ifndef COLOR_H
#define COLOR_H


#include <curses.h>
#include <ncurses.h>
#include "log.h"
#include "util.h"


enum ColorPairId {
  COLOR_PAIR_ID_DEFAULT,
  COLOR_PAIR_ID_MINE,
  COLOR_PAIR_ID_ZERO,
  COLOR_PAIR_ID_ONE,
  COLOR_PAIR_ID_TWO,
  COLOR_PAIR_ID_THREE,
  COLOR_PAIR_ID_FOUR,
  COLOR_PAIR_ID_FIVE,
  COLOR_PAIR_ID_SIX,
  COLOR_PAIR_ID_SEVEN,
  COLOR_PAIR_ID_EIGHT,
  COLOR_PAIR_ID_OK_MARKER,
  COLOR_PAIR_ID_MINE_MARKER,
  COLOR_PAIR_ID_MAX
};


void color_init();


#endif

