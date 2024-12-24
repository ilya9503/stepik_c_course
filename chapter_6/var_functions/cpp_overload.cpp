/*
    Пример перегрузки функций в С++
    Позволяет создавать несколько функций с одинаковыми именами, но разным набором параметров
    Перегрузка позволяет ускорить работу программы, вызвав подходящий вариант функции для конкретного случая
*/
#include<iostream>
using namespace std;
 
int modul(int x) 
{
    return (x < 0) ? -x : x;
}
 
double modul(double x) 
{
    return (x < 0) ? -x : x;
}
 
int main(void) {
    int a1 = modul(-3);
    int a2 = modul(-3.5);
    double a3 = modul(-3);
    double a4 = modul(-3.5);
 
    return 0;
}