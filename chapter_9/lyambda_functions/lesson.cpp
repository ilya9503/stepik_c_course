/*
    В стандарте компилятора С++11 появились, так называемые, лямбда-функции
        (еще говорят лямбда-выражения или анонимные функции).
    Лямбда-выражение позволяет создавать простой объект-функцию в любом допустимом месте программы.
        И одно из таких допустимых мест – аргумент обычной функции.
    Особенно удобны для алгоритмов STL или кратких функций
    Можно вызывать прямо при передаче аргумента в параметр функции 
    
    Синтаксис:
    [] ([параметры]) { <операторы тела функции>}


*/

#include <iostream>
#include <string>
 
using std::cout;
using std::cin;
using std::endl;
 
int main()
{
    auto r = [](int a) {
        cout << "Lambda-function: " << a << endl;
    };
 
    r(10);

    auto s { [](const char* msg, double x) {
        cout << msg << endl;
        return ++x;
    } };

    double b = s("increment", 5);

//    auto sum2 { [](int a, int b) -> double {return a+b;} };
    auto sum2 { [](auto a, auto b) -> auto {return a+b;} };

    double res_1 = sum2(3, 5);
    double res_2 = sum2(3.4, 5.3);
    cout << res_1 << " " << res_2 << endl;

    std::string res_3 = sum2(std::string("hello, "), std::string("world!"));
    cout << res_3 << endl;

 
    return 0;
}