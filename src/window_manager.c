#include "window_manager.h"
#include "log.h"
#include "util.h"


#define WINDOW_MANAGER_WINDOW_WIDTH 31
#define WINDOW_MANAGER_WINDOW_HEIGHT 15


void window_manager_init(struct WindowManager* window_manager) {
  for (int i = 0; i < WINDOW_ID_MAX; i++) {
    window_manager->window[i] = newwin(0, 0, 0, 0);
    window_manager->width[i] = WINDOW_MANAGER_WINDOW_WIDTH;
    window_manager->height[i] = WINDOW_MANAGER_WINDOW_HEIGHT;
    window_manager->left[i] = 0;
    window_manager->top[i] = 0;
    window_manager->enable[i] = false;
  }
}


void window_manager_print(
    struct WindowManager* window_manager,
    enum WindowId window_id
) {
  log_info_f(
      "{width: %d, height: %d, left: %d, top: %d, enable: %s}",
      window_manager->width[window_id],
      window_manager->height[window_id],
      window_manager->left[window_id],
      window_manager->top[window_id],
      boolean_as_string(window_manager->enable[window_id])
  );
}


void window_manager_set_left(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int left
) {
  window_manager->left[window_id] = left;
}


void window_manager_set_top(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int top
) {
  window_manager->top[window_id] = top;
}


int window_manager_get_width(
    struct WindowManager* window_manager,
    enum WindowId window_id
) {
  return window_manager->width[window_id];
}


void window_manager_set_width(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int width
) {
  window_manager->width[window_id] = width;
}


int window_manager_get_height(
    struct WindowManager* window_manager,
    enum WindowId window_id
) {
  return window_manager->height[window_id];
}


void window_manager_set_height(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int height
) {
  window_manager->height[window_id] = height;
}


WINDOW* window_manager_get_window(
    struct WindowManager* window_manager,
    enum WindowId window_id
) {
  return window_manager->window[window_id];
}


void window_manager_erase(struct WindowManager* window_manager) {
  for (int i = 0; i < WINDOW_ID_MAX; i++) {
    werase(window_manager->window[i]);
    window_manager->enable[i] = false;
  }
}


WINDOW* window_manager_setup_window(
    struct WindowManager* window_manager,
    enum WindowId window_id,
    int center_x,
    int center_y
) {
  window_manager->enable[window_id] = true;
  window_manager->left[window_id] = center_x - window_manager->width[window_id] / 2;
  window_manager->top[window_id] = center_y - window_manager->height[window_id] / 2;
  window_manager_print(window_manager, window_id);
  WINDOW* window = window_manager->window[window_id];
  wresize(window, window_manager->height[window_id], window_manager->width[window_id]);
  mvwin(window, window_manager->top[window_id], window_manager->left[window_id]);
  box(window, 0, 0);
  return window;
}


/**
 * This function should be called last.
 */
void window_manager_render(struct WindowManager* window_manager) {
  for (int i = 0; i < WINDOW_ID_MAX; i++) {
    if (!window_manager->enable[i]) continue;
    wrefresh(window_manager->window[i]);
  }
}
