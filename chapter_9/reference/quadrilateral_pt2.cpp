#include <iostream>
#include <math.h>

enum {corners = 4, min, max};

struct point {  // Точка в пространстве
    int x, y;
};

bool areEqual(double a, double b, double epsilon);                       // Функция сравнения чисел типа double
double get_length(const point& p1, const point& p2);                            // Вычисление длины стороны треугольника
double sq_tr (const point& p1, const point& p2, const point& p3);               // Вычисление  площади треугольника
bool quad_point_check(const point(&quad)[], const point& pt);                   // Проверяем, входит ли точка в пространство четырехугольника
point find_min_max_coords(const point(&quad)[], size_t ar_size, int choose);    // Выбираем максимальные и минимальные координаты из массива координат
int find_points_in_quad(const point(&quad)[], size_t ar_size);                  // Вычисляем количество точек, лежащих в пределах четырехугольника

int main()
{
    point figure[corners];      // Четырехугольник

    int count = 0;              // Вводим точки для четырехугольника
    while(count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2)
        count++;

    if(count != corners) {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }

    // здесь продолжайте функцию main
    size_t figure_size = sizeof(figure) / sizeof(*figure); 
    std::cout << find_points_in_quad(figure, figure_size) << std::endl;

    return 0;
}

/*  ====================================== БИБЛИОТЕКА ===================================================== */

// Функция сравнения чисел типа double
bool areEqual(double a, double b, double epsilon = 1e-9)
{
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

// Проверяем, входит ли точка в пространство четырехугольника
bool quad_point_check(const point(&quad)[], const point& pt)   // передаем массив по ссылке
{
    // Находим площадь четырехугольника
    double sq_quad = sq_tr(quad[0], quad[1], quad[3]) + sq_tr(quad[2], quad[1], quad[3]);
    // Находим сумму площадей треугольников, входящих в четырехугольник
    double sum_sq_tr = sq_tr(quad[0], quad[1], pt) + sq_tr(quad[1], quad[2], pt) + sq_tr(quad[2], quad[3], pt) + sq_tr(quad[3], quad[0], pt);
    // Сравниваем сумму площадей треугольников с площадью четырехугольника
    return areEqual(sq_quad, sum_sq_tr);
}

// Выбираем максимальные и минимальные координаты из массива координат
point find_min_max_coords(const point(&quad)[], size_t ar_size, int choose)
{
    point res;
    int index_x = 0;
    int index_y = 0;

    for(int i = 0; i < ar_size; ++i) {
        switch (choose) {
            case min:
                if(quad[index_x].x > quad[i].x)
                    index_x = i;
                if(quad[index_y].y > quad[i].y)
                    index_y = i;
                break;
            case max:
                if(quad[index_x].x < quad[i].x)
                    index_x = i;
                if(quad[index_y].y < quad[i].y)
                    index_y = i;
                break;        
        }
    }

    res.x = quad[index_x].x;
    res.y = quad[index_y].y;

    return res;
}

// Вычисляем количество точек, лежащих в пределах четырехугольника
int find_points_in_quad(const point(&quad)[], size_t ar_size)
{
    int count = 0;
    point p_min = find_min_max_coords(quad, ar_size, min);
    point p_max = find_min_max_coords(quad, ar_size, max);
    point temp;

    // Перебор целых чисел в диапазоне [x_min, x_max], [y_min, y_max]
    for (int i = p_min.x; i <= p_max.x; ++i) {
        temp.x = i;
        for (int j = p_min.y; j <= p_max.y; ++j) {
            temp.y = j;
            if(quad_point_check(quad, temp))
                count++;
        }
    }

    return count;
}