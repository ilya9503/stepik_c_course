/*
    Оператор return используется как:
        1. Возвращает определенное значение
        2. Завершает работу функции, передает действие следующему оператору (функции типа void)
    Функции = модули программы:
        *функции следует выполнять только свою узко поставленную задачу;
        *для решения поставленной задачи, функции следует использовать только переданные ей параметры;
        *если тело функции становится слишком большим – это повод задуматься над правильностью организации логики
            программы; возможно, подзадачу следует раздробить на более мелкие подзадачи;
        *в 99% случаях функции ничего не считывают с клавиатуры (из потока stdin) и ничего не выводят на экран
            (в поток stdout); если ваша функция делает это, убедитесь, что это действительно необходимо.

    Разница префиксной и постфиксной записи:
        1. b = ++x; // сначала х увеличится на 1, затем присвоится b
        1. b = x++; // сначала х присвоится b, затем увеличится на 1

    NULL - This macro expands to a null pointer constant. This is a special value that indicates
        that the pointer is not pointing to any object.
*/

#include <stdio.h>
#include <math.h>   // NAN
 
double sq4_x(double x)
{
         double res = (x < 0) ? NAN : pow(x, 0.25); // возведение числа в степень 1/2 = квадратный корень
         // NAN - Not A Number (float)
         return res;
}

double min_2(double a, double b)
{
         return (a < b) ? a : b;
}

double min_3(double a, double b, double c)
{
         double min_ab = min_2(a, b);
         return (min_ab < c) ? min_ab : c;
}
 
int main(void) 
{
         printf("%f\n", sq4_x(16));

         double x = 1, y = -2, z = 10;
 
         double res_1 = min_2(x, y);
         double res_2 = min_3(x, y, z);
         double res_3 = min_2(min_2(x, y), z);
         double res_4 = min_2(x, min_2(y, z));
 
         printf("res_1 = %.2f, res_2 = %.2f, res_3 = %.2f, res_4 = %.2f\n", 
                      res_1, res_2, res_3, res_4);

         return 0;
}
