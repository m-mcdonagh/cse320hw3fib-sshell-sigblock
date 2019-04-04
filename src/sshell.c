#include "shell.h"
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

BOOLEAN executeCommand(char** args){
	if (!args){
		printf("\n");
		return TRUE;
	}
	if (equals(*args, "exit"))
		return FALSE;
	if (equals(*args, "cd")){
		if (!*++args)
			fprintf(stderr, "No such directory.\n");
		else{
			char* cwd = malloc(256*sizeof(char));
			if ((cwd = getcwd(cwd, 256)) == NULL)
				fprintf(stderr, "Error retreiving Current Working Directory\n");
			else{
				char* nwd = malloc(strlen(cwd) + strlen(*args) + 2);
				strcpy(nwd, cwd);
				strcat(nwd, "/");
				strcat(nwd, *args);
				if (chdir(*args))
					fprintf(stderr, "No such directory \"%s\".\n", nwd);
				free(nwd);
				free(cwd);
			}
		}
		return TRUE;
	}

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
