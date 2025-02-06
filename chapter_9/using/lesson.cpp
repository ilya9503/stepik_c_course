/*
    Оператор using
    Назначения
        1.  Импорт элементов в модуль (файл). Пространсва имен, объекты и тд
                using <пространство имен>::<элемент>;
        2.  Определение псевдонимов типов
                using <alias> = <тип данных>;
            Полностью заменяет функционал typedef в Си
*/

#include <iostream>

namespace firstSpace {
    using std::cout;        // Импорт объектов cout/cin/endl в область firstSpace
    using std::endl;
    void foo()
    {
        cout << "function from firstSpace: foo()" << endl;
    }
 
    struct point {
        double x, y;
    };
}

// using namespace std  // Импорт пространства имен. Так лучше не делать, плохая практика. std содержит очень много всего 
using std::cout;        // Импорт объектов cout/cin/endl в глобальную область
using std::cin;
using std::endl;
using byte_8 = unsigned char;       // замена typedef
using point2D = firstSpace::point;  // псевдоним !типа данных! firstSpace::point
using func_ptr = float (*)(int);    // тип указателя на функцию с помощью using
//typedef float (*func_ptr)(int);     // тип указателя на функцию с помощью typedef
 
int main()
{
/*
    using std::cout;        // Импорт объектов cout/cin/endl в локальную область
    using std::cin;
    using std::endl;
*/
    char str[50];

    byte_8 byte;
    byte_8* byte_ptr;
    point2D pt;
 
    cin >> str;
    cout << "Hello, " << str << "!" << endl;
 
    return 0;
}