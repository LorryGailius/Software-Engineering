#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 0,b = 0,c = 0;

    scanf("%d %d %d",&a,&b,&c);

    int f[1000];

    f[0]= a; f[1] = b;

    for (int i = 2; i < c; i++)
    {
        f[i] = f[i-1] + f[i-2]; 
    }

    printf("%d",f[c-1]);
    
    return 0;
}