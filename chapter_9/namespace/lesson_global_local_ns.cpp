/*
    :: - символ раскрытия области видимости
    :: - глобальная область видимости
    Глобальная область видимости в Си попадает в глобальное пространство имен в С++
    std:: - область видимости std

*/

#include <iostream>

void foo()
{
    std::cout << "function: foo()" << std::endl;
}
 
int global_a = 5;
 
struct point {
    double x, y;
};

int main()
{
    point pt {};

    int global_a = 10;

    ::foo();
    // ::global_a - глобальная переменная, global_a - локальная переменная
    std::cout << ::global_a << " " << global_a << std::endl;
 
    return 0;
}