#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 0;
    float x = 0,sum = 0,vid = 0,min = 9999,max = -9999;

    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f",&x);
        sum += x;
        if(x > max){max = x;}
        if(x < min){min = x;}
    }

    vid = sum / n;
    
    printf("Suma = %.2f\n"
          "Vidurkis = %.2f\n"
          "Minimumas = %.2f\n"
          "Maximumas = %.2f\n",
          sum,vid,min,max
          );

    return 0;
}