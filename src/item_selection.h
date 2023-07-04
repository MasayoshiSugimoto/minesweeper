#ifndef ITEM_SELECTION_H
#define ITEM_SELECTION_H


#include "log.h"


struct ItemSelection {
  int selection;
  const int* items;
  size_t length;
};


void item_selection_init(
    struct ItemSelection* item_selection,
    const int* items,
    size_t length
);
void item_selection_move_cursor_up(struct ItemSelection* item_selection);
void item_selection_move_cursor_down(struct ItemSelection* item_selection);
int item_selection_get_selection(struct ItemSelection* item_selection);


#endif
