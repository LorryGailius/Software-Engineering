#include <stdio.h>
#include <stdlib.h>

int main(){
 
    int mleng = -1, mnum = 0,x = 0,stop = 0; 

    scanf("%d",&stop);

    while (x != stop)
    {
        int leng = 0, temp = 0;
        scanf("%d",&x);
        temp = x;

        //Skaiciuoja skaitmenu skaiciu
        while (temp > 0)
        {
            temp /= 10;
            leng++;
        }

        //Randa max skaitmenu turinti skaiciu
        if (leng > mleng)
        {
            mleng = leng;
            mnum = x;
        }
    }
    
    printf ("%d", mnum);

    return 0;
}