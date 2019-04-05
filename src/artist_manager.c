#include "defs.h"
#include "shell.h"
#include <stdio.h>
#define equals(s1, s2) !strcmp(s1, s2)
#define BOOLEAN char
#define TRUE 1
#define FALSE 0

char* helpstring = "help\t\tprints this very message!\n\
date\t\tprints the current date\n\
hire N\t\thires N many artists (creates processes for each)\n\
fire X\t\tfires the given artist X (kills process with PID X)\n\
fireall\t\tfires all artists (kills all child processes)\n\
assign X\tmarks the given artist X as assigned to a job (and the child process X prints it is assigned)\n\
withdraw X\tmarks the given artist X as unassigned (and the child process X prints it is withdrawn)\n\
list\t\tprints all artists in the form \"PID STATUS\" (ASSIGNED or WAITING)\n\
exit\t\texits the shell\n";

BOOLEAN executeCommand(char** args){
	if (!args || !*args)
		return TRUE;
	if (equals(*args, "help")){
		cse320_print( helpstring );
	}
	if (equals(*args, "date")){
	}
	if (equals(*args, "hire")){
	}
	if (equals(*args, "fire")){
	}
	if (equals(*args, "fireall")){
	}
	if (equals(*args, "assign")){
	}
	if (equals(*args, "withdraw")){
	}
	if (equals(*args, "list")){
	}
	if (equals(*args, "exit")){
		return FALSE;
	}
	return TRUE;
}

int main(void){
	shell_loop(32);
	exit(0);
}
