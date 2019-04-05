all:
	gcc src/artist_manager.c src/artist_ds.c src/artist.c src/defs.c src/error_checking.c -I./inc -o artist_manager

fib:
	gcc src/fib.c src/error_checking.c -I./inc -o fib

sshell:
	gcc src/sshell.c src/error_checking.c -I./inc -o simple_shell

sigblock:
	gcc src/sigblock.c src/error_checking.c -I./inc -o shell
	gcc src/child.c -o child

clean:
	rm artist_manager fib simple_shell shell child

