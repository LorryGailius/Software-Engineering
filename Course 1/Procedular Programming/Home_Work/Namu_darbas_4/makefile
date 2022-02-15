.DEFAULT_GOAL:=main

test.o: test.c
	gcc -c test.c -I.

main.o: main.c
	gcc -c main.c -I.

list.o: list.c list.h
	gcc -c list.c -I.
	
students.o: students.c students.h
	gcc -c students.c -I.

file.o: file.c file.h
	gcc -c file.c -I.

main: main.o list.o file.o students.o
	gcc -o main main.o list.o file.o students.o
	
test: test.o list.o file.o students.o
	gcc -o test test.o list.o file.o students.o