#ifndef UI_H
#define UI_H


#include "menu.h"
#include "game_menu.h"
#include "window_manager.h"
#include "terminal.h"
#include "manual.h"
#include "color.h"


/**
 * This struct is expected to contain all UI singletons.
 */
struct UI {
  struct Menu menu;
  struct ItemSelection game_menu;
  struct WindowManager window_manager;
  struct Terminal terminal;
  struct Manual manual;
};


void ui_init(struct UI* ui);


#endif
