#include <stdio.h>

int main(void)
{
    unsigned short a, b, h;
    scanf("%hu, %hu, %hu", &a, &b, &h);
//    printf("%hu %hu %hu \n", a, b, h);

    /* */
    double res = (a + b) / 2.0 * h;
    printf("%.1f", res);



    return 0;
}