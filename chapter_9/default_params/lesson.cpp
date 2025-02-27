/*
    Значения по умолчанию часто применяют в практике программирования
*/
#include <iostream>
#include <math.h>
 
using std::cout;
using std::cin;
using std::endl;

/*
    Параметр по умолчанию должен следовать после обычных параметров
*/
void show_data(const char* sep, int a=1, const char* str="Hi!", double b=-5.43)
{
    cout << sep << endl;
    cout << a << endl << str << endl << b << endl;
}
/*
int length(int a=0, int b, int c=0)  // ошибка
{
    return sqrt(a*a + b*b + c*c);
}
 
double length(double a=0, double b=0, double c)  // ошибка
{
    return sqrt(a*a + b*b + c*c);
}
*/
int length(int a, int b, int c=0)  // ok
{
    return sqrt(a*a + b*b + c*c);
}

double round_math(double x, int radix=0)
{
    double p = pow(10, radix);
    return round(x * p) / p;
}
 
int main()
{
    //show_data("Hello!");    // параметры по умолчанию, если передать аргумент, значения параметров изменятся

    double res_1 = round_math(4.5634);  // 5
    double res_2 = round_math(4.5634, 1); // 4.6
    double res_3 = round_math(4.5634, 3); // 4.563

    cout << res_1 << "\n" << res_2 << "\n" << res_3 << endl;

    return 0;
}