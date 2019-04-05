#include <sys/types.h>


// Defined in artist_ds.c
	struct artist;
	void newArtist(pid_t pid);
	void hire(int n);
	void fire(pid_t x);
	void fireall();
	void assign(pid_t x);
	void withdraw(pid_t x);
	void list();
