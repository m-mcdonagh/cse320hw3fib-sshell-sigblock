#ifndef ERROR_CHECKING
#define ERROR_CHECKING
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

pid_t Fork();
void Signal(int signum, __sighandler_t handler);
void childReaper(int sig);

#endif
