#include "game_menu.h"


const char* g_menu_items[] = {
  "Resume",
  "New Game",
  "Manual",
  "Quit"
};


const int new_game_items[] = {1, 2, 3};
const int in_game_items[] = {0, 1, 2, 3};


void game_menu_init_new_game(struct ItemSelection* item_selection) {
  item_selection_init(
      item_selection,
      new_game_items,
      array_size(new_game_items)
  );
}


void game_menu_init_in_game(struct ItemSelection* item_selection) {
  item_selection_init(
      item_selection,
      in_game_items,
      array_size(in_game_items)
  );
}
