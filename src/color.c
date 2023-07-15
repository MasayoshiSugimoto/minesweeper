#include "color.h"


struct ColorPair {
  enum ColorPairId id;
  short foreground_color;
  short background_color;
};


const struct ColorPair palette[] = {
  {COLOR_PAIR_ID_DEFAULT, COLOR_WHITE, COLOR_BLACK},
  {COLOR_PAIR_ID_MINE, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_ZERO, COLOR_WHITE, COLOR_BLACK},
  {COLOR_PAIR_ID_ONE, COLOR_CYAN, COLOR_BLACK},
  {COLOR_PAIR_ID_TWO, COLOR_BLUE, COLOR_BLACK},
  {COLOR_PAIR_ID_THREE, COLOR_YELLOW, COLOR_BLACK},
  {COLOR_PAIR_ID_FOUR, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_FIVE, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_SIX, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_SEVEN, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_EIGHT, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_OK_MARKER, COLOR_GREEN, COLOR_BLACK},
  {COLOR_PAIR_ID_MINE_MARKER, COLOR_RED, COLOR_BLACK},
  {COLOR_PAIR_ID_BOARD_BOARDER, COLOR_BLACK, COLOR_WHITE},
};


void color_init() {
  if (has_colors() == FALSE) {
    endwin();
    log_fatal("Your terminal does not support color\n");
  }

  start_color();

  for (int i = 0; i < array_size(palette); i++) {
    const struct ColorPair* pair = &palette[i];
    init_pair(pair->id, pair->foreground_color, pair->background_color);
  }

}
