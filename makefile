
all: main.c 1AHTB.c
	gcc -o main main.c 1AHTB.c -I .

debug: main.c 1AHTB.c
	gcc -g -o main main.c 1AHTB.c -I .
