#include <time.h>
#include "input.h"
#include "render.h"
#include "ui.h"
#include "consts.h"


/********************************************************************************
* Main
********************************************************************************/


#if DEBUG_ENABLE_TEST

void debug_init() {
  log_info("DEBUG MODE ON");
  log_info("=============\n");
}

#endif


struct UI ui;
struct Game game;


void main_update_game(struct Game* game, struct UI* ui) {
  uint64_t now_millisecond;
  uint64_t delta_time_millisecond;
  switch (game->game_state) {
    case GAME_STATE_IN_GAME:
      if (game_board_is_lost(&game->game_board)) {
        game_set_game_state(game, GAME_STATE_GAME_OVER);
      } else if (game_board_is_win(&game->game_board)) {
        game_set_game_state(game, GAME_STATE_GAME_WON);
      }
      break;
    case GAME_STATE_START_SCREEN:
      now_millisecond = get_current_millisecond();
      delta_time_millisecond = now_millisecond - ui->start_screen.start_millisecond;
      if (delta_time_millisecond >= ui->start_screen.logo_display_time_millisecond) {
        log_info("New game_state: GAME_STATE_CREDITS");
        game->game_state = GAME_STATE_CREDITS;
      }
      break;
    case GAME_STATE_CREDITS:
      now_millisecond = get_current_millisecond();
      delta_time_millisecond = now_millisecond - ui->start_screen.start_millisecond;
      int total_time = ui->start_screen.logo_display_time_millisecond
        + ui->start_screen.made_by_time_millisecond;
      if (delta_time_millisecond >= total_time) {
        log_info("New game_state: GAME_STATE_START_MENU");
        game->game_state = GAME_STATE_START_MENU;
      }
      break;
    default:
      // Do nothing.
      break;
  }
}


int main() {
  log_init();
  srand(time(NULL));
  game_init_medium_mode(&game);
  ui_init(&ui);


#if DEBUG_ENABLE_TEST
  debug_init();
#endif

  // Loop to track cursor position
  while (true) {
    log_info("LOOP BEGIN");
    if (DEBUG_GAME_BOARD_SHOW_ALL) game_board_show_all(&game.game_board);

    struct Terminal* terminal = &ui.terminal;
    terminal_init(terminal);
    log_info_f("terminal={width:%d, height:%d}", terminal->width, terminal->height);
    struct Vector center = terminal_center(terminal);

    if (terminal->height < TERMINAL_MIN_HEIGHT || terminal->width < TERMINAL_MIN_WIDTH) {
      log_info("Terminal is too small. Please resize the terminal.");
      erase();
      addstr(
          "Terminal is too small.\n"
          "Please resize the terminal.\n"
      );
      refresh();
      getch();  // Wait for resize.
      continue;
    }

    render(center, &ui, &game);

    input_update(&game, &ui);
    game_print_state(game.game_state);
    if (game.game_state == GAME_STATE_QUIT) {
      break;
    }

    main_update_game(&game, &ui);
  }

  endwin();  // End ncurses.
  return 0;
}

