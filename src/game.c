#include "game.h"

#define BOMB_POURCENTAGE 10


const char* g_game_state_strings[] = {
  "GAME_STATE_START_MENU",
  "GAME_STATE_IN_GAME",
  "GAME_STATE_GAME_OVER",
  "GAME_STATE_GAME_WON",
  "GAME_STATE_MENU",
  "GAME_STATE_MANUAL",
  "GAME_STATE_QUIT",
  "GAME_STATE_MAX"
};


void game_init(struct Game* game, int width, int height) {
  log_info_f("game_init(game, %d, %d)", width, height);
  game->cursor.x = 0;
  game->cursor.y = 0;
  game_board_init(&game->game_board, width, height);
  game->game_state = GAME_STATE_START_MENU;
}


void game_init_easy_mode(struct Game* game) {
  int width = 9;
  int height = 5;
  game_init(game, width, height);
  game_board_setup_game(&game->game_board, BOMB_POURCENTAGE);
}


void game_init_medium_mode(struct Game* game) {
  int width = 17;
  int height = 9;
  game_init(game, width, height);
  game_board_setup_game(&game->game_board, BOMB_POURCENTAGE);
}


void game_init_hard_mode(struct Game* game) {
  int width = 31;
  int height = 15;
  game_init(game, width, height);
  game_board_setup_game(&game->game_board, BOMB_POURCENTAGE);
}


void game_print_state(enum GameState game_state) {
  log_info_f("Game state: %s", g_game_state_strings[game_state]);
}


void game_set_game_state(struct Game* game, enum GameState game_state) {
  log_info_f("Game state set to: %s", g_game_state_strings[game_state]);
  if (game_state == GAME_STATE_MAX) return;
  game->game_state = game_state;
}
