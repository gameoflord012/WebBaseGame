#ifndef DONUT_LOG_H
#define DONUT_LOG_H

#include <assert.h>

#define DONUT_COLOR_RED     "\x1b[31m"
#define DONUT_COLOR_GREEN   "\x1b[32m"
#define DONUT_COLOR_YELLOW  "\x1b[33m"
#define DONUT_COLOR_BLUE    "\x1b[34m"
#define DONUT_COLOR_RESET   "\x1b[0m"

#define Donut_Log(...)          { printf(DONUT_COLOR_BLUE "[INFO]    " DONUT_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogWarning(...)   { printf(DONUT_COLOR_YELLOW "[WARNING] " DONUT_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogError(...)     { printf(DONUT_COLOR_RED "[ERROR]   " DONUT_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogCritical(...)  { printf(DONUT_COLOR_RED "[CRITICAL]" DONUT_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogDebug(...)     { printf(DONUT_COLOR_YELLOW "[DEBUG]   " DONUT_COLOR_RESET);  printf(__VA_ARGS__); printf("\n"); }
#define Donut_LogExtra() { printf("at %s:%d\n", __FILE__, __LINE__); }

#define Donut_assert(condition, ...) \
    if(!(condition)) { \
        printf(DONUT_COLOR_RED "[Assertion failed]" DONUT_COLOR_RESET); Donut_LogExtra(); \
        __VA_ARGS__; \
        std::abort(); \
    } 

#endif