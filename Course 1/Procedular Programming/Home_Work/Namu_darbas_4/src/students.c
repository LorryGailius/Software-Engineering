#include <students.h>

// Saves student info to a given pointer, reads from a given file pointer(could be stdin)
int get_student(FILE *fs, student_t* std)
{
    int retValue = 1, valid;
    char ch;
        
        valid = (fscanf(fs,"%20s %d %lf", &(std->name), &(std->courseNo), &(std->grade)) == 3);

        if (valid)
        {
            ch = getc(fs);
        }

        valid = valid && (isspace(ch) || feof(fs));

        if (!valid)
        {
            retValue = 0;
            if ((!feof(fs)))
            {
                puts("Invalid student input!\n");
                while(!isspace(getc(fs)))
                    ;
            }
        }

    return retValue;
}

// Used in node_insert() to insert a student next to other students attending the same course
int cmp_course(const void * s1, const void * s2, size_t size)
{
    return !(((student_t*)s1)->courseNo ==  ((student_t*)s2)->courseNo);
}

// Used in print_list() to print out information of student_t structure
void print_student(const void * std, FILE *fs)
{
    fprintf(fs,"--------------------------------------------------------\n");
    fprintf(fs, "%20s | %d : %4.2lf\n", ((student_t*)std)->name, ((student_t*)std)->courseNo, ((student_t*)std)->grade);
    fprintf(fs,"--------------------------------------------------------\n");
}