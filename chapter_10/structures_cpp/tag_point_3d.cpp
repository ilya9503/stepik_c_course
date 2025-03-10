#include <iostream>
enum{total_points = 100};

// здесь объявляйте структуру
struct tag_point_3d {
    int x, y, z;
};


int main(void)
{
    // здесь продолжайте программу
    tag_point_3d points[total_points];
    int total = 0;
    while(std::cin >> points[total].x >> points[total].y >> points[total].z && total < total_points)
        ++total;

    std::cout << points[0].x << " " << points[0].y << " " << points[0].z << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}