#ifndef DONUT_LOG_H
#define DONUT_LOG_H

#include <assert.h>

#define Donut_ANSI_COLOR_RED     "\x1b[31m"
#define Donut_ANSI_COLOR_GREEN   "\x1b[32m"
#define Donut_ANSI_COLOR_YELLOW  "\x1b[33m"
#define Donut_ANSI_COLOR_BLUE    "\x1b[34m"
#define Donut_ANSI_COLOR_RESET   "\x1b[0m"

#define Donut_Log(...)          { printf(Donut_ANSI_COLOR_BLUE "[INFO]    " Donut_ANSI_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogWarning(...)   { printf(Donut_ANSI_COLOR_YELLOW "[WARNING] " Donut_ANSI_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogError(...)     { printf(Donut_ANSI_COLOR_RED "[ERROR]   " Donut_ANSI_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogCritical(...)  { printf(Donut_ANSI_COLOR_RED "[CRITICAL]" Donut_ANSI_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogDebug(...)     { printf(Donut_ANSI_COLOR_YELLOW "[DEBUG]   " Donut_ANSI_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogExtra() { printf("%s:%d\n", __FILE__, __LINE__); }

#define Donut_assert(condition, ...) \
    if(!(condition)) {  \
        Donut_LogExtra(); \
        __VA_ARGS__; \
        assert(condition); \
    } 

#endif