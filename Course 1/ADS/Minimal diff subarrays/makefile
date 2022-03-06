.DEFAULT_GOAL:=main

split.o: split.c
	gcc -c split.c -I.

sort.o: sort.c
	gcc -c sort.c -I.

main.o: main.c
	gcc -c main.c -I.

main: main.o split.o sort.o
	gcc -o main main.o split.o sort.o