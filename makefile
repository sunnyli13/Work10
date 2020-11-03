all: player.o main.o
	gcc -o main player.o main.o
player.o: player.h player.c
	gcc -c player.c
main.o: main.c player.h
	gcc -c main.c
run:
	./main