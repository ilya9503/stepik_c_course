#include <iostream>
#include <math.h>
#include <iomanip>  // fixed, setprecision

using POINT = struct {
    double x;
    double y;
};

double get_length(const POINT& p1, const POINT& p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main()
{
    POINT p1{-2.5, 7.8}, p2{11.4, 43.2};
    std::cout << std::fixed << std::setprecision(2) << get_length(p1, p2) << std::endl;

    return 0;
}