#ifndef GAME_MENU_H
#define GAME_MENU_H


#include "util.h"
#include "window_manager.h"
#include "log.h"
#include "game.h"
#include "item_selection.h"


enum GameMenuCommand {
  GAME_MENU_RESUME,
  GAME_MENU_NEW_GAME,
  GAME_MENU_MANUAL,
  GAME_MENU_QUIT,
  GAME_MENU_COMMAND_MAX
};


struct GameMenu {
  struct ItemSelection item_selection;
};


void game_menu_init_new_game(struct ItemSelection* item_selection);
void game_menu_init_in_game(struct ItemSelection* item_selection);


#endif
