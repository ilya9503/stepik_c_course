#include <stdio.h>


typedef
enum 
{
    coord_int = 1,
    coord_double
}TYPE_COORD;

typedef
union 
{
    int coord_i;
    double coord_d;
} COORD;

typedef
struct
{
    COORD x,y;
    TYPE_COORD type;
}POINT2;

int main(void)
{
    POINT2 pt;
    scanf("%u", &pt.type);
    scanf(pt.type == 1 ? "%d %d" : "%lf %lf", &pt.x, &pt.y);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}