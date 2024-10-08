/*
    Геометрическая прогрессия
    bn+1 = b1 * q^(n-1)
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int b1, q, n;
    scanf("%d; %d; %d", &b1, &q, &n);

/*
    Геометрическая прогрессия
    bn+1 = b1 * q^(n-1)
*/
    for(int i = 0 ; i < n ; ++i)
        printf("%.f ", b1 * pow(q, i));

    return 0;
}