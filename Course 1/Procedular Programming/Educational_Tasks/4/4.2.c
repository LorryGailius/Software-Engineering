#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 0,b = 0,c = 0;

    scanf("%d %d %d",&a,&b,&c);

    for (int i = a; i < b; i++)
    {
        if(i%c == 1 && i > 0){printf("%d\n",i);}
    }

    return 0;
}