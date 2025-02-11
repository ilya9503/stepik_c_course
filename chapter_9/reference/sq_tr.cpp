#include <iostream>
#include <math.h>   // sqrt, pow
#include <iomanip>  // fixed, setprecision

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

// Точка в пространстве
struct point {
    int x, y;
};

// Вычисление длины стороны треугольника
double get_length(const point& p1, const point& p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Вычисление  площади треугольника
double sq_tr (const point& p1, const point& p2, const point& p3)
{
    double a = get_length(p1, p2);
    double b = get_length(p2, p3);
    double c = get_length(p3, p1);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a)* (p - b)* (p - c));
}

int main()
{
    // здесь продолжайте функцию main
    point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << fixed << setprecision(2) << sq_tr(p1, p2, p3) << endl;

    return 0;
}