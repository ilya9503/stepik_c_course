/*
    Давайте теперь посмотрим, как можно динамически создавать массивы из объектов определенного типа данных. Для этого в С++ применяются похожие операторы:

    new [] – для выделения памяти под указанное число объектов;
    delete [] – для освобождения памяти массива объектов.
*/

#include <iostream>
#include <math.h>
 
using std::cout;
using std::endl;
 
struct point {
private:
    int x, y;
public:
    point() 
    { 
        cout << "вызов конструктора объекта" << endl; 
        x = 0; y = 0;
    }
    point(int x, int y) 
    { 
        cout << "вызов конструктора объекта" << endl; 
        this->x = x; this->y = y;
    }
 
    ~point()  // деструктор
    { 
        cout << "вызов деструктора объекта" << endl; 
    }
 
    double length() { return sqrt(x*x + y*y); }
    void sum(const point& pt)
    {
        this->x += pt.x;
        this->y += pt.y;
    }
 
    void set_coords(int x, int y) 
    { 
        if(x < -100 || x > 100 || y < -100 || y > 100)
            return;
 
        this->x = x; 
        this->y = y; 
    }
 
    void get_coords(int& x, int& y) {x = this->x; y = this->y; }
    int get_x() { return this->x; }
    int get_y() { return this->y; }
};

int main()
{

    point* pt = new point[3];       // выделяем память для массива из 3-ех объектов (3 конструктора)
    for(int i = 0; i < 3; ++i)
        cout << pt[i].get_x() << " " << pt[i].get_y() << endl;
    // что то делаем
    delete [] pt;                   // освобождаем память для массива из 3-ех объектов (3 деструктора)

    double* v3 = new double[3];
    delete [] v3;

    return 0;
}