#include "sshell.h"
#include "error_checking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#define BOOLEAN char
#define TRUE 1
#define FALSE 0
#define equals(s1, s2)	!strcmp(s1, s2)

void childReaper(int sig){
	while(waitpid(-1, NULL, WNOHANG) > 0);
	return;
}

BOOLEAN executeCommand(char** args){
	if (equals(*args, "exit"))
		return FALSE;
	
	pid_t pid;
	if ((pid = Fork()) == 0){
		execvp(*args, args);
		fprintf(stderr, "Command not found.\n");
		exit(EXIT_FAILURE);
	}
	pause();
	return TRUE;
}

int main(void) {
	if (signal(SIGCHLD, childReaper) == SIG_ERR){
		fprintf(stderr, "Signal Error\n");
	}
	shell_loop(32);
}
