.DEFAULT_GOAL:=main

priority.o: priority.c
	gcc -c priority.c -I.

main.o: main.c
	gcc -c main.c -I.

main: main.o priority.o
	gcc -o main main.o priority.o