#include "menu.h"


const char* MENU_SELECTION_NAMES[] = {
  "easy",
  "medium",
  "hard"
};


const char* menu_selection_as_string(enum MenuSelection selection) {
  if (selection < MENU_SELECTION_MAX) {
    return MENU_SELECTION_NAMES[selection];
  } else {
    log_fatal_f("Invalid menu selection: %d", selection);
  }
}


void menu_init(struct Menu* menu, struct WindowManager* window_manager) {
  menu->menu_selection = MENU_SELECTION_MEDIUM;
}


void menu_move_cursor_up(struct Menu* menu) {
  log_info("Up key pressed.");
  if (menu->menu_selection == 0) {
    menu->menu_selection = MENU_SELECTION_HARD;
  } else {
    menu->menu_selection = menu->menu_selection - 1;
  }
  log_info_f(
      "menu->menu_selection=%s",
      menu_selection_as_string(menu->menu_selection)
  );
}


void menu_move_cursor_down(struct Menu* menu) {
  log_info("Down key pressed.");
  menu->menu_selection = (menu->menu_selection + 1) % MENU_SELECTION_MAX;
  log_info_f(
      "menu->menu_selection=%s",
      menu_selection_as_string(menu->menu_selection)
  );
}

