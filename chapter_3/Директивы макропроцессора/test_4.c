#include <stdio.h>
#include <math.h>

#define MAX_LENGTH   100

int main(void)
{
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Input error!");
        return 0;
    }

    double length = sqrt(pow((double)x, 2.0) + pow((double)y, 2.0));
    length > MAX_LENGTH ?
        printf("Radius length exceeds value of MAX_LENGTH")
                        :
        printf("%.2f", length);

    return 0;
}