#include <iostream>
#include <math.h>

enum {corners = 4};

// Точка в пространстве
struct point {
    int x, y;
};

// Функция сравнения чисел типа double
bool areEqual(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) < epsilon;
}

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

bool quad_point_check(const point(&quad)[corners], const point& pt)   // передаем массив по ссылке
{
    // Находим площадь четырехугольника
    double sq_quad = sq_tr(quad[0], quad[1], quad[3]) + sq_tr(quad[2], quad[1], quad[3]);
    // Находим сумму площадей треугольников, входящих в четырехугольник
    double sum_sq_tr = sq_tr(quad[0], quad[1], pt) + sq_tr(quad[1], quad[2], pt) + sq_tr(quad[2], quad[3], pt) + sq_tr(quad[3], quad[0], pt);
    // Сравниваем сумму площадей треугольников с площадью четырехугольника
    return areEqual(sq_quad, sum_sq_tr);
}

int main()
{
    point figure[corners];      // Четырехугольник
    point pt;                   // Проверяем, лежит ли данная точка в пределах четырехугольника

    // Вводим точки для четырехугольника
    int count = 0;
    while(count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2)
        count++;

    if(count != corners) {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }
    // Вводим точку для проверки
    if(scanf("%d; %d", &pt.x, &pt.y) != 2) {
        puts("Неверное количество или формат входных данных.");
        return 2;        
    }

    // здесь продолжайте функцию main
    puts(quad_point_check(figure, pt) ? "yes" : "no");

    return 0;
}