#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <students.h>
#include <list.h>

int menu_input(char *menuOptions[], int menuSize, char *inputMsg);

void get_list(node_t** head, char *fileName);

#endif