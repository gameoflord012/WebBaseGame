#ifndef DONUT_LOG_H
#define DONUT_LOG_H

#define DONUT_ANSI_COLOR_RED     "\x1b[31m"
#define DONUT_ANSI_COLOR_GREEN   "\x1b[32m"
#define DONUT_ANSI_COLOR_YELLOW  "\x1b[33m"
#define DONUT_ANSI_COLOR_BLUE    "\x1b[34m"
#define DONUT_ANSI_COLOR_RESET   "\x1b[0m"


#define DONUT_Log(...)          { printf(DONUT_ANSI_COLOR_BLUE "[INFO]    " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogWarning(...)   { printf(DONUT_ANSI_COLOR_YELLOW "[WARNING] " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogError(...)     { printf(DONUT_ANSI_COLOR_RED "[ERROR]   " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogCritical(...)  { printf(DONUT_ANSI_COLOR_RED "[CRITICAL]" DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogDebug(...)     { printf(DONUT_ANSI_COLOR_YELLOW "[DEBUG]   " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }

#endif