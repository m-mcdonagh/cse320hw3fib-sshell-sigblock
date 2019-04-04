#include "error_checking.h"
#include <signal.h>
#include <unistd.h>

int main(void){
	sigset_t sigIntSet;
	sigemptyset(	&sigIntSet);
	sigaddset(	&sigIntSet, 	SIGINT);
	sigprocmask(	SIG_BLOCK, 	&sigIntSet,	NULL);
	
	int i;
	printf("1\n");
	for (i=2; i<=5; i++){
		sleep(1);
		printf("%d\n", i);
	}

	sigprocmask(	SIG_UNBLOCK,	&sigIntSet,	NULL);

	for (; i<=10; i++){
		sleep(1);
		printf("%d\n", i);
	}
	exit(0);
}

