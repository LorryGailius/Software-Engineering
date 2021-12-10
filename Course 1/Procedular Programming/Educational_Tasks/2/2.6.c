#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x,y,z,m,mn;

   scanf("%d %d %d",&x,&y,&z);

   m = (y > z) ? y : z;
   mn = (y < z) ? y : z;

   printf("Maksimali reiksme skaiciu %d %d %d yra %d\n"
          "Minimali reiksme skaiciu %d %d %d yra %d\n",
          x,y,z,(x >(m)) ? x: m,
          x,y,z,(x <(mn)) ? x: mn);

    return 0;
}
