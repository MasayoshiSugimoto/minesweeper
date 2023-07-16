#ifndef START_SCREEN_H
#define START_SCREEN_H


#include "util.h"


struct StartScreen {
  int start_millisecond;
  int logo_display_time_millisecond;
  int made_by_time_millisecond;
};


void start_screen_init(struct StartScreen* start_screen);


#endif

