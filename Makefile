all:
	gcc src/artist_manager.c src/artist_ds.c src/defs.c -I./inc -o artist_manager

fib:
	gcc src/fib.c -o fib

sshell:
	gcc src/sshell.c -o simple_shell

sigblock:
	gcc src/sigblock.c -o shell

clean:
	rm artist_manager fib simple_shell shell
