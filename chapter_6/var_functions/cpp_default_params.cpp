/*
    Параметры со значениями по умолчанию
    Параметрам функции присваивается начальное значение по умолчанию
    параметры со значениями по умолчанию должны быть записаны в конце списка параметров функции
        void my_func(int a, int b = 1, int c = 1);    //правильное объявление
        void my_func(int a, int b, int c = 1);        //правильное объявление
        void my_func(int a=1, int b, int c = 1);      //неправильное объявление
        void my_func(int a, int b = 1, int c);        //неправильное объявление
*/
#include<iostream>
using namespace std;
 
void show_args(short a=10, double b=20.0, int c=30) 
{
    printf("a = %d, b = %.2f, c = %d\n", a, b, c);
}
 
int main() {
    show_args();    // все параметры по умолчанию 
    show_args(1);   // параметр а будет равен 1, остальные по умолчанию
    show_args(1, 2);
    show_args(1, 2, 3);
 
    return 0;
}