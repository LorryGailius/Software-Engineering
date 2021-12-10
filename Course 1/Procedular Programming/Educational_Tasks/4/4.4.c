#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 0,b = 0,c = 0,dbd = 0,mbk = 1;

    scanf("%d %d %d",&a,&b,&c);
    
    //DBD
    for (int i = 1; i <= a && i <= b && i <= c; i++)
    {   
        if(a % i == 0 && b % i == 0 && c % i == 0)
        {
            dbd = i;
            
        }
    }

    //MBK
    while (1)
    {
        if (mbk % a == 0 && mbk % b == 0 && mbk % c == 0)
        {
            break;
        }
        mbk++;
    }
    
    printf("Skaiciu %d %d %d\n"
           "Didziausias bendras daliklis = %d\n"
           "Maziausias bendras kartotinis = %d\n",
           a,b,c,dbd,mbk);
    
    return 0;
}