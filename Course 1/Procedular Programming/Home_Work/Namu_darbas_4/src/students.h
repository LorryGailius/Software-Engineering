#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct student_t
{
    char name[21];
    int courseNo;
    double grade;
}student_t;

int get_student(FILE *fs, student_t* std);

int cmp_course(const void * s1, const void * s2, size_t size);

void print_student(const void * std, FILE *fs);

#endif