#include <math.h>
#include <stdio.h>

float rada(float degre)
{
    return (degre * M_PI / 180);
}

int main()
{
    printf("the radian of is : %f\n", rada(45.0));
    return (0);
}