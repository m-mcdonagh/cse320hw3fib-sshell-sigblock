all:
	gcc src/artist_manager.c src/artist_ds.c src/defs.c -I./inc -o artist_manager

fib:
	gcc src/fib.c -I./inc -o fib

sshell:
	gcc src/sshell.c -I./inc -o simple_shell

sigblock:
	gcc src/sigblock.c -I./inc -o shell
	gcc src/child.c -Iinc -o child

clean:
	rm artist_manager fib simple_shell shell child

