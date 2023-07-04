#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H


#include <curses.h>
#include <ncurses.h>


enum WindowId {
  WINDOW_ID_GAME_OVER,
  WINDOW_ID_GAME_WON,
  WINDOW_ID_MENU,
  WINDOW_ID_GAME_MENU,
  WINDOW_ID_MANUAL,
  WINDOW_ID_MAX
};


struct WindowManager {
  WINDOW* window[WINDOW_ID_MAX];
  int width[WINDOW_ID_MAX];
  int height[WINDOW_ID_MAX];
  int left[WINDOW_ID_MAX];
  int top[WINDOW_ID_MAX];
  bool enable[WINDOW_ID_MAX];
};


void window_manager_init(struct WindowManager* window_manager);
void window_manager_set_left(
   struct WindowManager* window_manager,
   enum WindowId window_id,
   int left
);
void window_manager_set_top(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int top
);
int window_manager_get_width(
    struct WindowManager* window_manager,
    enum WindowId window_id
);
void window_manager_set_width(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int width
);
int window_manager_get_height(
    struct WindowManager* window_manager,
    enum WindowId window_id
);
void window_manager_set_height(
    struct WindowManager* window_manader,
    enum WindowId window_id,
    int height
);
WINDOW* window_manager_get_window(
    struct WindowManager* window_manager,
    enum WindowId window_id
);
void window_manager_erase(struct WindowManager* window_manager);
WINDOW* window_manager_setup_window(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int center_x,
    int center_y
);
void window_manager_render(struct WindowManager* window_manager);


#endif
