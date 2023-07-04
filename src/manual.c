#include "manual.h"


const char* const manual_text[] = {
  "",
  "            MANUAL",
  "            ======",
  "",
  "Minesweeper is a game in     ",
  "which you have to find bombs.",
  "You win the game when you    ",
  "have uncovered all empty     ",
  "cells correctly.",
  "",
  "# Controls",
  "",
  "ESC      Show Menu.          ",
  "X        Set bomb marker.    ",
  "SPACE    Reveal cell.        ",
  "UP ARROW Move cursor up.     ",
  "UP DOWN  Move cursor down.   ",
  "UP LEFT  Move cursor left.   ",
  "UP RIGHT Move cursor right.  ",
};


void manual_init(struct Manual* manual) {
  manual->line_offset = 0;
}


void manual_move_up(struct Manual* manual) {
  log_info("Move manual up");
  manual->line_offset = imax(0, manual->line_offset - 1);
  log_info_f("New line offset: %d", manual->line_offset);
}


void manual_move_down(struct Manual* manual) {
  log_info("Move manual down");
  int last = array_size(manual_text) - 1;
  manual->line_offset = imin(manual->line_offset + 1, last);
  log_info_f("New line offset: %d", manual->line_offset);
}


void manual_get_page(struct Manual* manual, const char** lines, size_t length) {
  int offset = manual->line_offset;
  for (int i = 0; i < length; i++) {
    if (i + offset < array_size(manual_text)) {
      lines[i] = manual_text[offset + i];
    } else {
      lines[i] = "";
    }
  }
}
