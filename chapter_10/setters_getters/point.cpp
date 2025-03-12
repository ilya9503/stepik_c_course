#include <iostream>
#include <iomanip>

enum data_type { data_none = 1, data_int, data_double };

struct point {
private:
    enum { max_coords = 3 };

    union {
        int v_int;
        double v_double;
    } coords[max_coords];

    data_type type = data_none;

// здесь продолжайте описание структуры point
public:
// перегруженный сеттер для записи координат в массив coords в поле v_int
void set_coords(int x, int y, int z)
{
    this->coords[0].v_int = x;
    this->coords[1].v_int = y;
    this->coords[2].v_int = z;
    this->type = data_int;
}

// перегруженный сеттер для записи координат в массив coords в поле v_double
void set_coords(double x, double y, double z)
{
    this->coords[0].v_double = x;
    this->coords[1].v_double = y;
    this->coords[2].v_double = z;
    this->type = data_double;
}

// метод возвращает значение переменной type
data_type get_type() { return this->type; }

// метод возвращает значение константы max_coords
int get_size() { return this->max_coords; }

// перегруженный геттер для записи по ссылкам x, y, z значений из массива coords поля v_int
bool get_coords(int& x, int& y, int& z)
{
    bool res = false;
    if(this->type == data_int) {
        x = this->coords[0].v_int;
        y = this->coords[1].v_int;
        z = this->coords[2].v_int;
        res = true;
    }
    return res;
}

// перегруженный геттер для записи по ссылкам x, y, z значений из массива coords поля v_double
bool get_coords(double& x, double& y, double& z)
{
    bool res = false;
    if(this->type == data_double) {
        x = this->coords[0].v_double;
        y = this->coords[1].v_double;
        z = this->coords[2].v_double;
        res = true;
    }
    return res;
}
};

int main(void)
{
    // здесь продолжайте функцию main
    int xi, yi, zi;
    double xd, yd, zd;
    point pt;
    //std::cin >> xi >> yi >> zi;

    pt.set_coords(5, -8, 34);
    pt.get_coords(xi, yi, zi);
    pt.get_coords(xd, yd, zd);

    if(pt.get_type() == data_int) {
        std::cout << xi << ' ' << yi << ' ' << zi << std::endl;
    }
    else if(pt.get_type() == data_double) {
        std::cout << std::fixed << std::setprecision(1) << xd << ' ' << yd << ' ' << zd << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}