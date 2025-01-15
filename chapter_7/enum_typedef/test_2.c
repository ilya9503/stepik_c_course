#include <stdio.h>

typedef enum {_perimetr = 1, _square = 2} calc_types;

double calc_rect(double width, double height, calc_types type)
{
    if(type == _square)
        return width * height;
    else if (type == _perimetr)
        return 2 * (width + height);
    else
        return -1;
}

int main(void)
{
    calc_types t;
    double w, h;
    scanf("%d %lf %lf", &t, &w, &h);
    printf("%.1f", calc_rect(w, h, t));

    return 0;
}