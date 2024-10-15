#include <stdio.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);

        do {                    // выводим все числа из диапазона [a, b]

            int rev_num = 0;    // сюда собираем число в обратном порядке
            int old_m;          // предыдущее значение m
            int temp_m = m;

            while (temp_m) {
                 int rem = temp_m % 10;             // выделяем последнюю цифру
                 old_m = temp_m;
                 
                 rev_num = rev_num * 10 + rem;      // сборка обратного числа
                 temp_m /= 10;                      // отрезаем последнюю цифру
            }

            if ((temp_m == rev_num || old_m == rev_num) && temp_m != 0)
                printf("%d ", m);

        ++m;
    } while (m <= n);




    return 0;
}