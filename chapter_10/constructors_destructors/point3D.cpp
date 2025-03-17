/*
    struct в C++ – это практически тот же class, но с разными модификаторами доступа по умолчанию.
    В С++ struct чаще используют для простых структур данных, а class – для сложных объектов с инкапсуляцией.
    Различия:
        В struct все члены (поля и методы) по умолчанию имеют публичный (public) доступ.
        В class все члены по умолчанию имеют закрытый (private) доступ.
*/
#include <iostream>
#include <math.h>

// здесь объявляйте структуры
struct point3D {
private:
    int x, y, z;
public:
    // Конструктор
    point3D(int x=0, int y=0, int z=0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    // Деструктор
    ~point3D() {}
    // Возвращает значения координат из приватных переменных x, y, z
    void get_coords(int& x, int& y, int& z)
    {
        x = this->x;
        y = this->y;
        z = this->z;       
    }
};

struct line3D {
private:
    point3D start_pt, end_pt;
public:
    // Конструктор 
    line3D(point3D start_pt, point3D end_pt)
    {
        this->start_pt = start_pt;
        this->end_pt = end_pt;
    }
    // Деструктор
    ~line3D()
    {
        int x0, y0, z0, x1, y1, z1;
        this->start_pt.get_coords(x0, y0, z0);
        this->end_pt.get_coords(x1, y1, z1);
        printf("Deleted line: (%d, %d, %d) (%d, %d, %d)", x0, y0, z0, x1, y1, z1);
    }
    // Возвращает длину линии
    double length()
    {
        int x0, y0, z0, x1, y1, z1;
        this->start_pt.get_coords(x0, y0, z0);
        this->end_pt.get_coords(x1, y1, z1);
        return sqrt(pow((x0-x1), 2) + pow((y0-y1), 2) + pow((z0-z1), 2));
    }
    // Возвращает константную ссылку на приватную переменную start_pt
    const point3D& get_coords_start() { return this->start_pt; }
    // Возвращает константную ссылку на приватную переменную end_pt
    const point3D& get_coords_end() { return this->end_pt; }
};

int main(void)
{
    line3D line(point3D(-5, 100, 45), point3D(0, 32, -42));
//    std::cout << line.length() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}