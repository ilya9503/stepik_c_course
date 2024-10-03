/*
    Цикл while:
    Цикл с предусловием
    Тело цикла - оператор или блок операторов выполняющиеся внутри цикла
    Итерация - один проход выполнения операторов
    ! Выполняется пока истинно условие !
*/
#include <stdio.h>

int main(void)
{
    int n;
    int s = 0;

    if (scanf("%d", &n) != 1) {
        printf("Error input");
        return 0;
    }

    /*
        s = n^2 + (n-1)^2 + (n-2)^2 + ... + 1^2
    */
    /*
    while (n > 0) {
        // s = s + n*n
        s += n * n;
        n--;
    }
    while (--n > 0) {
        // s = s + n*n
        s += n * n;
    }
    */
   int i = 0;
   /*
        цикл работает пока верно условие
        1. Выполняется ++i (префиксная форма) i = i + 1
        2. Сравнение i <= n. Если true переходим к 3 пункту. Если false, цикл завершается
        3. Проверка i <= 10. Если true, цикл выполняется
   */ 
   while (++i <= n && i <= 10)
        // s = s + i * i
        s += i * i;
   

    printf("s = %d\n", s);
    

    return 0;
}