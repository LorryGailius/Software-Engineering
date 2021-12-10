#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,y,z;

    scanf("%lf %lf %lf",&x,&y,&z);

    printf("x+4y+z^3 = %0.3f\n",x+4*y+pow(z,3));

    printf("(x + sqrt(y))(z^4-|z|+46.3) = %0.3f\n",(x+sqrt(y))*(pow(z,4)-abs(z)+46.3));

    return 0;
}
