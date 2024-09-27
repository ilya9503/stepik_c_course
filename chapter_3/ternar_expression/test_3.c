#include <stdio.h>

int main(void)
{
    short type = 0;
    double w, h;

    if(scanf("%hd %lf %lf", &type, &w, &h) != 3) {
        printf("Input error.");
        return 0;
    }

    // здесь продолжайте программу
    /*
    if (type == 1)
        printf("%.1f", w * h);
    else if (type == 2)
        printf("%.1f", 2 * (w + h));
    else
        printf("%d", -1);
    */
    (type == 1) ? printf("%.1f", w * h) : ((type == 2) ? printf("%.1f", 2 * (w + h)) : printf("%d", -1));

    return 0;
}