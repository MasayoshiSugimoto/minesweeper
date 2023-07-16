#ifndef GAME_H
#define GAME_H


#include "game_board.h"
#include "cursor.h"


enum GameState {
  GAME_STATE_START_MENU,
  GAME_STATE_IN_GAME,
  GAME_STATE_GAME_OVER,
  GAME_STATE_GAME_WON,
  GAME_STATE_MENU,
  GAME_STATE_MANUAL,
  GAME_STATE_START_SCREEN,
  GAME_STATE_QUIT,
  GAME_STATE_MAX
};


struct Game {
  struct GameBoard game_board;
  struct Cursor cursor; 
  enum GameState game_state;
};


void game_init_easy_mode(struct Game* game);
void game_init_medium_mode(struct Game* game);
void game_init_hard_mode(struct Game* game);
void game_print_state(enum GameState game_state);
void game_set_game_state(struct Game* game, enum GameState game_state);


#endif
