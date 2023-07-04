#ifndef MENU_H
#define MENU_H

#include <curses.h>
#include <ncurses.h>
#include "log.h"
#include "window_manager.h"
#include "game.h"


enum MenuSelection {
  MENU_SELECTION_EASY = 0,
  MENU_SELECTION_MEDIUM = 1,
  MENU_SELECTION_HARD = 2,
  MENU_SELECTION_MAX = 3
};


struct Menu {
  enum MenuSelection menu_selection;
};


void menu_init(struct Menu* menu, struct WindowManager* window_manager);
void menu_move_cursor_up(struct Menu* menu);
void menu_move_cursor_down(struct Menu* menu);


#endif
