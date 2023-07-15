#include "ui.h"


#define UI_MENU_WIDTH 31
#define UI_MENU_HEIGHT 15


void ui_init_ncurses() {
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
}


void ui_game_over_init(struct WindowManager* window_manager) {
  window_manager_set_width(window_manager, WINDOW_ID_GAME_OVER, 13);
  window_manager_set_height(window_manager, WINDOW_ID_GAME_OVER, 3);
}


void ui_game_won_init(struct WindowManager* window_manager) {
  window_manager_set_width(window_manager, WINDOW_ID_GAME_WON, 11);
  window_manager_set_height(window_manager, WINDOW_ID_GAME_WON, 3);
}


void ui_game_menu_init(struct WindowManager* window_manager) {
  window_manager_set_width(window_manager, WINDOW_ID_GAME_MENU, UI_MENU_WIDTH); 
  window_manager_set_height(window_manager, WINDOW_ID_GAME_MENU, UI_MENU_HEIGHT);
}


void ui_menu_init(struct WindowManager* window_manager) {
  window_manager_set_width(window_manager, WINDOW_ID_MENU, UI_MENU_WIDTH);
  window_manager_set_height(window_manager, WINDOW_ID_MENU, UI_MENU_HEIGHT);
}


void ui_init(struct UI* ui) {
  ui_init_ncurses();
  color_init();
  window_manager_init(&ui->window_manager);
  ui_game_over_init(&ui->window_manager);
  ui_game_won_init(&ui->window_manager);
  ui_game_menu_init(&ui->window_manager);
  ui_menu_init(&ui->window_manager);
  menu_init(&ui->menu, &ui->window_manager);
  game_menu_init_new_game(&ui->game_menu);
  manual_init(&ui->manual);
}
