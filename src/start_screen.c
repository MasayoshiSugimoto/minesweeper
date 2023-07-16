#include "start_screen.h"


void start_screen_init(struct StartScreen* start_screen) {
  start_screen->start_millisecond = get_current_millisecond();
  start_screen->logo_display_time_millisecond = 2000;
  start_screen->made_by_time_millisecond = 0;
}

