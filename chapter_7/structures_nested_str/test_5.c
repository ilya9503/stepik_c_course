#include <stdio.h>

// здесь объявляйте структуру
enum {total_points = 100};

struct tag_point_3d {
    int x;
    int y;
    int z;
};


int main(void)
{
    // здесь продолжайте программу
    struct tag_point_3d points[total_points];
    int total = 0;

    while (total < total_points && scanf("%d %d %d", &points[total].x, &points[total].y, &points[total].z) == 3)
        ++total;

    printf("%d %d %d", points[total-1].x, points[total-1].y, points[total-1].z, total);
        
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}