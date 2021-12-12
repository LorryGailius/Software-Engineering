#include <stdlib.h>
#include <stdio.h>

long getFileSize(char *fileName);

int main()
{
    
    return 0;
}

long getFileSize(char *fileName)
{
    FILE *file;

    if(file = fopen(fileName,"rb"))
    {
        fseek(file,0,SEEK_END);
		
		int ret = ftell(file);
        
        return ret;
    }
    else
    {
        return -1;
    }
}
