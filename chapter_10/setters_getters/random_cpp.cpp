#include <iostream>
#include <random>
#include <iomanip>

#define MIN     -100.0
#define MAX     100.0
enum {total_points = 128};

struct tag_point {
    float x, y;
};

int main(void)
{
    // здесь продолжайте функцию main
    tag_point ps[total_points];
    double mean_x, mean_y;
    double sum_x {0.0};
    double sum_y {0.0};

    std::random_device rd;  // Источник случайности
    std::mt19937 gen(rd()); // Генератор случайных чисел Mersenne Twister

    std::uniform_real_distribution<double> dist(MIN, MAX); // Диапазон [MIN, MAX]


    for(int i = 0; i < total_points; ++i) {
        ps[i].x = dist(gen);
        ps[i].y = dist(gen);
        sum_x += ps[i].x;
        sum_y += ps[i].y;
    }

    mean_x = sum_x / total_points;
    mean_y = sum_y / total_points;

     
    std::cout << std::fixed << std::setprecision(2) << "mean_x = " << mean_x << "; mean_y = " << mean_y << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}