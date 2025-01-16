/*
    Объявление массива из структур
    В итоге получаем массив figure, каждый элемент которого является структурой типа struct tag_point:
*/
#include <stdio.h>

enum {max_points=10};
 
struct tag_point {
    double x, y, z;
};

int main(void) 
{
    struct tag_point figure[max_points];
    int figure_points = 0;       // число точек в фигуре

    figure[0].x = 1.2;
    figure[0].y = -5.6;
    figure[0].z = 10.0;
    
    figure[1].x = 12.4;
    figure[1].y = 3.2;
    figure[1].z = 7.6;
    
    figure_points = 2;
 
    return 0;
}