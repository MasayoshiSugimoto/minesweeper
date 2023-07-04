#include "input.h"


#define KEY_ESC 27


void input_setup_start_menu(struct Game* game, struct ItemSelection* game_menu) {
  struct GameBoard* game_board = &game->game_board;
  game_set_game_state(game, GAME_STATE_START_MENU);
  if (game_board_is_playing(game_board)) {
    game_menu_init_in_game(game_menu);
  } else {
    game_menu_init_new_game(game_menu);
  }
}


void input_update_in_game(struct Game* game, int input) {
  struct GameBoard* game_board = &game->game_board;
  struct Cursor* cursor = &game->cursor;
  switch (input) {
    case KEY_DOWN:
      game_board_move_cursor(game_board, cursor, 0, 1);
      cursor_dump(cursor);
      break;
    case KEY_UP:
      game_board_move_cursor(game_board, cursor, 0, -1);
      cursor_dump(cursor);
      break;
    case KEY_LEFT:
      game_board_move_cursor(game_board, cursor, -1, 0);
      cursor_dump(cursor);
      break;
    case KEY_RIGHT:
      game_board_move_cursor(game_board, cursor, 1, 0);
      cursor_dump(cursor);
      break;
    case ' ':
      game_board_play_cell(game_board, cursor->x, cursor->y);
      break;
    case 'o':
      game_board_switch_ok_marker(game_board, cursor->x, cursor->y);
      break;
    case 'x':
      game_board_switch_mine_marker(game_board, cursor->x, cursor->y);
      break;
  }
}


void input_menu_update(struct Menu* menu, int input, struct Game* game) {
  switch (input) {
    case KEY_DOWN:
      menu_move_cursor_down(menu);
      break;
    case KEY_UP:
      menu_move_cursor_up(menu);
      break;
    case KEY_RESIZE:
      break;
    default:
      switch (menu->menu_selection) {
        case MENU_SELECTION_EASY:
          game_init_easy_mode(game);
          game_set_game_state(game, GAME_STATE_IN_GAME);
          break;
        case MENU_SELECTION_MEDIUM:
          game_init_medium_mode(game);
          game_set_game_state(game, GAME_STATE_IN_GAME);
          break;
        case MENU_SELECTION_HARD:
          game_init_hard_mode(game);
          game_set_game_state(game, GAME_STATE_IN_GAME);
          break;
        default:
          log_fatal_f("Invalid menu selection: %d", menu->menu_selection);
      }
  }
}


void input_game_menu_update(
    int input,
    struct ItemSelection* game_menu,
    struct Manual* manual,
    struct Game* game
) {
  switch (input) {
    case KEY_DOWN:
      item_selection_move_cursor_down(game_menu);
      break;
    case KEY_UP:
      item_selection_move_cursor_up(game_menu);
      break;
    case KEY_RESIZE:
    case KEY_ESC:
      break;
    default:
      switch (item_selection_get_selection(game_menu)) {
        case GAME_MENU_RESUME:
          log_info("Resuming game.");
          game_set_game_state(game, GAME_STATE_IN_GAME);
          break;
        case GAME_MENU_NEW_GAME:
          log_info("Starting new game.");
          game_set_game_state(game, GAME_STATE_MENU);
          break;
        case GAME_MENU_MANUAL:
          log_info("Opening manual.");
          manual_init(manual);
          game_set_game_state(game, GAME_STATE_MANUAL);
          break;
        case GAME_MENU_QUIT:
          log_info("Quiting...");
          game_set_game_state(game, GAME_STATE_QUIT);
          break;
        default:
          log_fatal_f("Invalid menu selection: %d", item_selection_get_selection(game_menu));
      }
  }
}


void input_log_key_pressed(int input) {
  char* key = NULL;
  switch (input) {
    case KEY_BREAK:
      key = "KEY_BREAK";
      break;
    case KEY_DOWN:
      key = "KEY_DOWN";
      break;
    case KEY_UP:
      key = "KEY_UP";
      break;
    case KEY_LEFT:
      key = "KEY_LEFT";
      break;
    case KEY_RIGHT:
      key = "KEY_RIGHT";
      break;
    case KEY_HOME:
      key = "KEY_HOME";
      break;
    case KEY_BACKSPACE:
      key = "KEY_BACKSPACE";
      break;
    case KEY_F0:
      key = "KEY_F0";
      break;
    case KEY_DL:
      key = "KEY_DL";
      break;
    case KEY_IL:
      key = "KEY_IL";
      break;
    case KEY_DC:
      key = "KEY_DC";
      break;
    case KEY_IC:
      key = "KEY_IC";
      break;
    case KEY_EIC:
      key = "KEY_EIC";
      break;
    case KEY_CLEAR:
      key = "KEY_CLEAR";
      break;
    case KEY_EOS:
      key = "KEY_EOS";
      break;
    case KEY_EOL:
      key = "KEY_EOL";
      break;
    case KEY_SF:
      key = "KEY_SF";
      break;
    case KEY_SR:
      key = "KEY_SR";
      break;
    case KEY_NPAGE:
      key = "KEY_NPAGE";
      break;
    case KEY_PPAGE:
      key = "KEY_PPAGE";
      break;
    case KEY_STAB:
      key = "KEY_STAB";
      break;
    case KEY_CTAB:
      key = "KEY_CTAB";
      break;
    case KEY_CATAB:
      key = "KEY_CATAB";
      break;
    case KEY_ENTER:
      key = "KEY_ENTER";
      break;
    case KEY_SRESET:
      key = "KEY_SRESET";
      break;
    case KEY_RESET:
      key = "KEY_RESET";
      break;
    case KEY_PRINT:
      key = "KEY_PRINT";
      break;
    case KEY_LL:
      key = "KEY_LL";
      break;
    case KEY_A1:
      key = "KEY_A1";
      break;
    case KEY_A3:
      key = "KEY_A3";
      break;
    case KEY_B2:
      key = "KEY_B2";
      break;
    case KEY_C1:
      key = "KEY_C1";
      break;
    case KEY_C3:
      key = "KEY_C3";
      break;
    case KEY_BTAB:
      key = "KEY_BTAB";
      break;
    case KEY_BEG:
      key = "KEY_BEG";
      break;
    case KEY_CANCEL:
      key = "KEY_CANCEL";
      break;
    case KEY_CLOSE:
      key = "KEY_CLOSE";
      break;
    case KEY_COMMAND:
      key = "KEY_COMMAND";
      break;
    case KEY_COPY:
      key = "KEY_COPY";
      break;
    case KEY_CREATE:
      key = "KEY_CREATE";
      break;
    case KEY_END:
      key = "KEY_END";
      break;
    case KEY_EXIT:
      key = "KEY_EXIT";
      break;
    case KEY_FIND:
      key = "KEY_FIND";
      break;
    case KEY_HELP:
      key = "KEY_HELP";
      break;
    case KEY_MARK:
      key = "KEY_MARK";
      break;
    case KEY_MESSAGE:
      key = "KEY_MESSAGE";
      break;
    case KEY_MOUSE:
      key = "KEY_MOUSE";
      break;
    case KEY_MOVE:
      key = "KEY_MOVE";
      break;
    case KEY_NEXT:
      key = "KEY_NEXT";
      break;
    case KEY_OPEN:
      key = "KEY_OPEN";
      break;
    case KEY_OPTIONS:
      key = "KEY_OPTIONS";
      break;
    case KEY_PREVIOUS:
      key = "KEY_PREVIOUS";
      break;
    case KEY_REDO:
      key = "KEY_REDO";
      break;
    case KEY_REFERENCE:
      key = "KEY_REFERENCE";
      break;
    case KEY_REFRESH:
      key = "KEY_REFRESH";
      break;
    case KEY_REPLACE:
      key = "KEY_REPLACE";
      break;
    case KEY_RESIZE:
      key = "KEY_RESIZE";
      break;
    case KEY_RESTART:
      key = "KEY_RESTART";
      break;
    case KEY_RESUME:
      key = "KEY_RESUME";
      break;
    case KEY_SAVE:
      key = "KEY_SAVE";
      break;
    case KEY_SBEG:
      key = "KEY_SBEG";
      break;
    case KEY_SCANCEL:
      key = "KEY_SCANCEL";
      break;
    case KEY_SCOMMAND:
      key = "KEY_SCOMMAND";
      break;
    case KEY_SCOPY:
      key = "KEY_SCOPY";
      break;
    case KEY_SCREATE:
      key = "KEY_SCREATE";
      break;
    case KEY_SDC:
      key = "KEY_SDC";
      break;
    case KEY_SDL:
      key = "KEY_SDL";
      break;
    case KEY_SELECT:
      key = "KEY_SELECT";
      break;
    case KEY_SEND:
      key = "KEY_SEND";
      break;
    case KEY_SEOL:
      key = "KEY_SEOL";
      break;
    case KEY_SEXIT:
      key = "KEY_SEXIT";
      break;
    case KEY_SFIND:
      key = "KEY_SFIND";
      break;
    case KEY_SHELP:
      key = "KEY_SHELP";
      break;
    case KEY_SHOME:
      key = "KEY_SHOME";
      break;
    case KEY_SIC:
      key = "KEY_SIC";
      break;
    case KEY_SLEFT:
      key = "KEY_SLEFT";
      break;
    case KEY_SMESSAGE:
      key = "KEY_SMESSAGE";
      break;
    case KEY_SMOVE:
      key = "KEY_SMOVE";
      break;
    case KEY_SNEXT:
      key = "KEY_SNEXT";
      break;
    case KEY_SOPTIONS:
      key = "KEY_SOPTIONS";
      break;
    case KEY_SPREVIOUS:
      key = "KEY_SPREVIOUS";
      break;
    case KEY_SPRINT:
      key = "KEY_SPRINT";
      break;
    case KEY_SREDO:
      key = "KEY_SREDO";
      break;
    case KEY_SREPLACE:
      key = "KEY_SREPLACE";
      break;
    case KEY_SRIGHT:
      key = "KEY_SRIGHT";
      break;
    case KEY_SRSUME:
      key = "KEY_SRSUME";
      break;
    case KEY_SSAVE:
      key = "KEY_SSAVE";
      break;
    case KEY_SSUSPEND:
      key = "KEY_SSUSPEND";
      break;
    case KEY_SUNDO:
      key = "KEY_SUNDO";
      break;
    case KEY_SUSPEND:
      key = "KEY_SUSPEND";
      break;
    case KEY_UNDO:
      key = "KEY_UNDO";
      break;
  }
  if (key != NULL) {
    log_info_f("Key pressed: %s", key);
  } else {
    log_info_f("Key pressed: {unicode: %d, character: '%c'}", input, (char)input);
  }
}


void input_manual_update(struct Manual* manual, int input, struct Game* game) {
  switch (input) {
    case KEY_DOWN:
      manual_move_down(manual);
      break;
    case KEY_UP:
      manual_move_up(manual);
      break;
  }
}


void input_update(struct Game* game, struct UI* ui) {
  int input = getch();
  input_log_key_pressed(input);
  enum GameState game_state = game->game_state;

  game_print_state(game_state);

  if (input == KEY_ESC) {
    input_setup_start_menu(game, &ui->game_menu);
    return;
  }

  switch (game_state) {
    case GAME_STATE_START_MENU:
      input_game_menu_update(input, &ui->game_menu, &ui->manual, game);
      break;
    case GAME_STATE_IN_GAME:
      input_update_in_game(game, input);
      break;
    case GAME_STATE_GAME_OVER:
      input_setup_start_menu(game, &ui->game_menu);
      break;
    case GAME_STATE_GAME_WON:
      input_setup_start_menu(game, &ui->game_menu);
      break;
    case GAME_STATE_MENU:
      input_menu_update(&ui->menu, input, game);
      break;
    case GAME_STATE_MANUAL:
      input_manual_update(&ui->manual, input, game);
      break;
    default:
      log_fatal_f("Invalid game_state=%d", game_state);
  }
}

