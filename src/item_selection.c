#include "item_selection.h"


void item_selection_init(
    struct ItemSelection* item_selection,
    const int* items,
    size_t length
) {
  item_selection->selection = 0;
  item_selection->items = items;
  item_selection->length = length;
}


void item_selection_move_cursor_up(struct ItemSelection* item_selection) {
  log_info("Move cursor up.");
  int last = item_selection->length - 1;
  item_selection->selection = item_selection->selection - 1 >= 0
    ? item_selection->selection - 1
    : last;
}


void item_selection_move_cursor_down(struct ItemSelection* item_selection) {
  log_info("Move cursor down.");
  item_selection->selection = item_selection->selection + 1 < item_selection->length
    ? item_selection->selection + 1
    : 0;
}


int item_selection_get_selection(struct ItemSelection* item_selection) {
  return item_selection->items[item_selection->selection];
}
