all: main.x

main.x:
	gcc src/main.c src/defs.c -I./inc

clean:
	rm a.out
