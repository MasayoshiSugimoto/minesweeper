#include "cursor.h"


void cursor_dump(struct Cursor* cursor) {
  log_info_f("cursor: x=%d, y=%d", cursor->x, cursor->y);
}

