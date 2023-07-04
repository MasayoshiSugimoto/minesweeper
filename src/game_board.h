#ifndef GAME_BOARD_H
#define GAME_BOARD_H


#include "util.h"
#include "cursor.h"
#include <stdbool.h>
#include <curses.h>


#define BOARD_CELL_TYPE_EMPTY ' '
#define BOARD_CELL_TYPE_HIDDEN ACS_CKBOARD
#define BOARD_CELL_TYPE_MINE 'M'
#define BOARD_CELL_TYPE_OK_MARKER 'O'
#define BOARD_CELL_TYPE_MINE_MARKER 'X'

#define GAME_BOARD_WIDTH_MAX 64
#define GAME_BOARD_HEIGHT_MAX 64
#define GAME_BOARD_SIZE_MAX (GAME_BOARD_WIDTH_MAX * GAME_BOARD_HEIGHT_MAX)


struct GameBoard {
  int width;
  int height;
  char board[GAME_BOARD_SIZE_MAX];
  bool visibility_map[GAME_BOARD_SIZE_MAX];
  char markers[GAME_BOARD_SIZE_MAX];
};


void game_board_init(struct GameBoard* game_board, int width, int height);
void game_board_setup_game(struct GameBoard* game_board, int pourcentage);
void game_board_move_cursor(
    struct GameBoard* game_board,
    struct Cursor* cursor,
    int x,
    int y
);
void game_board_play_cell(struct GameBoard* game_board, int x, int y);
void game_board_switch_ok_marker(struct GameBoard* game_board, int x, int y);
void game_board_switch_mine_marker(struct GameBoard* game_board, int x, int y);
void game_board_show_all(struct GameBoard* game_board);
bool game_board_is_win(struct GameBoard* game_board);
bool game_board_is_lost(struct GameBoard* game_board);
int game_board_get_index(struct GameBoard* game_board, int x, int y);
bool game_board_is_playing(struct GameBoard* game_board);


#endif
