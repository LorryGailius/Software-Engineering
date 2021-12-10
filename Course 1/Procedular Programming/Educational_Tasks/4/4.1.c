#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
 
    double a = 0,b = 0,c = 0,discriminant,ans1 = 0,ans2 = 0;
 
    scanf("%lf %lf %lf",&a,&b,&c);
 
    discriminant = (b * b) - (4 * a * c);
 
    printf("D = %lf * %lf - 4 * %lf * %lf = %lf\n",b,b,a,c,discriminant);
 
    if (discriminant > 0) {
        ans1 = (-b + sqrt(discriminant)) / (2 * a);
        ans2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Atsakymu yra 2 ir jie yra : %.4f ir %.4f\n",ans1,ans2);
    }
 
    else if (discriminant == 0)
    {
         ans1 = -b / (2 * a);
        printf("Yra 1 atsakymas ir jis yra : %.4f\n",ans1);
    }
 
    else
    {
        printf("Atsakymu nera.\n");
    }
 
    return 0;
}