/*
    Напишите программу, которая читает из входного потока шестизначное натуральное
    число n. Определить, является ли оно счастливым.
    (Счастливым называют такое шестизначное число, в котором сумма его первых 
    трех цифр равна сумме его последних трех цифр.).
    Вывести в консоль "yes", если счастливое и "no" - в противном случае.
*/
#include <stdio.h>

int main(void)
{
    int n;          // вводим число
    int m = 0;      // половина числа
    int right = 0, left = 0;
    int zero_c = 0; // счетчик нулей

    scanf("%d", &n);

    for (int i = 1 ;i <= 6 ;++i ) {

        int temp = n % 10;
        n = n / 10;    
        m += temp;

        if(i == 3) {            // Правая часть
            right = m;
            m = 0;
        }

        if(i == 6) {            // Левая часть
            left = m;
            m = 0;
        }

        if(n == 0) ++zero_c;    // Считаем 0

//        printf("Inside of cycle: n = %d\n", n);
    }
//    printf("After cycle m = %d, n = %d\n", m, n );
//    printf("right = %d, left = %d\n", right, left);
    if(n || zero_c > 1){    // Проверяем корректный ли ввод
        printf("Input error. Wrong number of digits");
        return 0;
    }
    right == left ? printf("yes") : printf("no");

    return 0;
}