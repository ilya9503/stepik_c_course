#include <stdio.h>

int main(void)
{
    int x;
    // проверка на вверный ввод. scanf() возвращает 1 если ввод корретный
    if (scanf("%d", &x) != 1) {
        printf("Error input");
        return 0;   // завершение программы. Главной функции main(void)
    }
    
    if (x < 0) x = -x;  // операция взятия модуля числа
    printf("x = %d\n", x);

    if (!(x >= 3 && x <= 11))
        printf("x not in [3; 11]\n");
        
    // Проверка взаимоисключающих условий
    if (x < 0)
        printf("x < 0\n");
    else if (x > 0)
        printf("x > 0\n");
    else
        printf("x == 0\n");

    // Проверка невзаимоисключающих условий
    if (x < 10)
        printf("x in [0; 9]\n");
    else if (x < 100)
        printf("x in [10; 99]\n");
    else if (x < 1000)
        printf("x in [100; 999]\n");
    else
        printf("x > 999\n");   
    

    return 0;
}