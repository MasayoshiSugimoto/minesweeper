#include "log.h"


void log_init() {
  g_debug_file = fopen(DEBUG_FILE, "w+");
  if (g_debug_file == NULL) {
    log_fatal_f("fopen(\"%s\") failed (%d): %s\n", DEBUG_FILE, errno, strerror(errno));
  }
}
