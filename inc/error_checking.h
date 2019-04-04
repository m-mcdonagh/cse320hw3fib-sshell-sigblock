#ifndef ERROR_CHECKERS
#define ERROR_CHECKERS
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

pid_t Fork(){
	pid_t output;
	if ((output = fork()) < 0){
		fprintf(stderr, "Fork Error\n");
		exit(EXIT_FAILURE);
	}
	return output;
}

#endif
