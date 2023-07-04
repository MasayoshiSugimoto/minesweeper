#ifndef LOG_H
#define LOG_H


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define DEBUG_FILE "/tmp/minesweeper.log"
struct _IO_FILE* g_debug_file;


#define log_info(text) { \
  fprintf(g_debug_file, "[INFO][%s:%d] ", __FILE__, __LINE__); \
  fprintf(g_debug_file, text); \
  fprintf(g_debug_file, "\n"); \
  fflush(g_debug_file); \
}


#define log_info_f(pattern, ...) { \
  fprintf(g_debug_file, "[INFO][%s:%d] ", __FILE__, __LINE__); \
  fprintf(g_debug_file, pattern, __VA_ARGS__); \
  fprintf(g_debug_file, "\n"); \
  fflush(g_debug_file); \
}


#define log_error(text) { \
  fprintf(g_debug_file, "[ERROR][%s:%d] ", __FILE__, __LINE__); \
  fprintf(g_debug_file, text); \
  fprintf(g_debug_file, "\n"); \
  fflush(g_debug_file); \
}


#define log_error_f(pattern, ...) { \
  fprintf(g_debug_file, "[ERROR][%s:%d] ", __FILE__, __LINE__); \
  fprintf(g_debug_file, pattern, __VA_ARGS__); \
  fprintf(g_debug_file, "\n"); \
  fflush(g_debug_file); \
}


#define log_fatal(text) { \
  fprintf(g_debug_file, "[FATAL][%s:%d] ", __FILE__, __LINE__); \
  fprintf(g_debug_file, text); \
  fprintf(g_debug_file, "\n"); \
  fflush(g_debug_file); \
  exit(1); \
}


#define log_fatal_f(pattern, ...) { \
  fprintf(g_debug_file, "[FATAL][%s:%d] ", __FILE__, __LINE__); \
  fprintf(g_debug_file, pattern, __VA_ARGS__); \
  fprintf(g_debug_file, "\n"); \
  fflush(g_debug_file); \
  exit(1); \
}


void log_init();


#endif

