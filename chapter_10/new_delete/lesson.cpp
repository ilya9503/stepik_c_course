/*
    10.4 Операторы new / delete и new [] / delete []
    В языке Си функции malloc(), calloc(), realloc() и free() выделяют и освобождают
        память для структуры не вызывая конструкторов и деструкторов (для структур в С++)
    Выделяют и освобождают нужное количество байт в куче (не в стеке) и все.

    Поэтому в языке С++ ввели операторы new / delete
    Нужны для корректной работы с памятью при создании/уничтожении объектов (ООП)

    new – для выделения памяти под указанный тип данных с автоматическим вызовом конструктора;
    delete – освобождение памяти с автоматическим вызовом деструктора.
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
    point* pt;          // указатель на структуру point
    pt = new point(10, 20);     // выделил память под point + вызвал конструктор
    //pt = new point; вызовет конструктор со значениями по умолчанию
    cout << pt->get_x() << " " << pt->get_y() << endl;

    delete pt;          // освободил память из под point + вызвал деструктор

/*    
    // Выделение памяти под структуру в языке Си
    pt = (point *)malloc(sizeof(point));
    // что то делаем
    free(pt);
*/

    int* ptr_int = new int(-123);       // выделяем память под тип int и задаем начальное зн-е

    std::cout << *ptr_int << endl;

    delete ptr_int;                     // освобождаем память 
 
    return 0;
}