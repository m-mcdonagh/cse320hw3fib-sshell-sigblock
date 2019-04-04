#include "shell.h"
#include "error_checking.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>
#define equals(s1, s2) !strcmp(s1, s2)
#define BOOLEAN char
#define TRUE 1
#define FALSE 0

BOOLEAN executeCommand(char** args){
	if (!args || !*args)
		return TRUE;
	if (equals(*args, "exit"))
		return FALSE;
	if (equals(*args, "run")){
		pid_t pid;
		if (Fork() == 0){
			char* args[2] = {"./child", NULL};
			execvp(args[0], args);
			fprintf(stderr, "Error running %s.", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	return TRUE;
}

int main(void) {
	sigset_t sigIntSet;
	sigemptyset(	&sigIntSet);
	sigaddset(	&sigIntSet, 	SIGINT);
	sigprocmask(	SIG_BLOCK, 	&sigIntSet,	NULL);

	Signal(SIGCHLD, childReaper);

	shell_loop(8);
	exit(0);
}
