// 12 Uzduotis
// Laurynas Gailius - 1 Kursas ; 2 Grupe 1 Pogrupis

// Parašyti funkciją, kuri randa ir atspausdina visus žodžius,
// kurie vienodai skaitomi iš pradžios ir iš galo.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef int (*filter_func_t)(char*);
#define BUFFER_SIZE 1024
#define DELIM " \n\r"

int getInputOutputFromArgs(int argc, char **argv, FILE **input, FILE **output);
FILE* getValidFile(char* name);
void filterFile(FILE *input, FILE *output, filter_func_t filter);
char* filterLine(char *buffer, filter_func_t filter);
int isPalindrome(char *token);

int main(int argc, char **argv)
{
    FILE *input = NULL;
    FILE *output = NULL;

    if(getInputOutputFromArgs(argc, argv, &input, &output) == 0)
    {
        return 0;
    }

    filterFile(input, output, isPalindrome);

    if (output != stdout) {fclose(output);}
    fclose(input);

    return 0;
}

int getInputOutputFromArgs(int argc, char **argv, FILE **input, FILE **output)
{
    if(argc == 3) 
    {
        printf("Use \"a -help\" for more information.\n");
        if (!(*input = fopen(argv[1], "r")))
        {
            char name[256] = { 0 };
            *input = getValidFile(name);
        }

        *output = fopen(argv[2], "w");
    }
    else if (argc == 2)
    {
        if ((strcmp(argv[1], "-help")) == 0)
        {
            printf
                (
                    "The program finds and prints all words that read the same from beginning and end.\n"
                    "Pass input and output files as parameters of the program ex. \"a.exe input.in output.out\")\n"
                    "If there is no output file given, the program will write out the result to stdout\n"
                    "If there is no input file given, the program will ask the user to enter input file name\n"
                );
            return 0;
        }
        else
        {
            if (!(*input = fopen(argv[1], "r")))
            {
                printf("Use \"a -help\" for more information.\n");
                printf("File could not be opened or does not exist! Please enter a valid file name: \n");
                char name[256] = { 0 };
                *input = getValidFile(name);
            }
        }

    }

    else if (argc == 1)
    {
        printf("Use \"a -help\" for more information.\n");
        printf("No input file entered, please enter a valid input file name:\n");
        char name[256] = { 0 };
        *input = getValidFile(name);
    }
    
    else
    {
        printf("Too many arguments!\n");
        printf("Use \"a -help\" for more information.\n");
        return 0;
    }

    if(!(*output)) 
    {
        printf("Output file is not given or could not be created, output is now set to stdout\n");
        *output = stdout;
    }
}

void filterFile(FILE *input, FILE *output, filter_func_t filter)
{
    char *buffer = (char*) malloc(sizeof(char) * BUFFER_SIZE);

    while (fgets(buffer, BUFFER_SIZE, input)) 
    {
        char* Palindromes  = filterLine(buffer, filter);
        if (strcmp(Palindromes,"\0") != 0)
        {
            fprintf(output, "%s\n", Palindromes);
        }
        free(Palindromes);
    }
    free(buffer);
}

FILE* getValidFile(char* name) 
{
    FILE *is;
    int valid;
    do 
    {
        valid = scanf("%s", name);
        valid = valid && ((is = fopen(name, "r")));
        if(!valid) 
        {
            printf("File could not be opened or does not exist! Please enter a valid file name: \n");
            while(getchar() != '\n')
                ;
        }
    } while(!valid);

    return is;
}

char* filterLine(char *buffer, filter_func_t filter)
{
    char *token, *word = NULL;
    size_t i = 0;
    word = (char*) calloc(BUFFER_SIZE, sizeof(char));

    if(strcmp(buffer, "\r\n") == 0) 
    {
        return word;
    }

    token = strtok(buffer, DELIM);
    while(token) 
    {
        if (filter(token))
        {
            size_t len = strlen(token);
            
            strcpy(word + i, token);
            word[i + len] = ' ';
            i += len + 1;
        }
        token = strtok(NULL, DELIM);
    }

    return word;
}

int isPalindrome(char *token)
{
    size_t len = strlen(token);

    for (size_t i = 0; i < len / 2; i++)
    {
        if (tolower(token[i]) != tolower(token[len - i - 1]))
        {
            return 0;
        }
    }
    
    return 1;
}