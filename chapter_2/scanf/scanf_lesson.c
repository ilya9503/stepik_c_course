#include <stdio.h>

int main(void)
{
    char byte1 = '0', byte2 = '0';
    long long var_lli = 0;
    double var_d = 0;
    unsigned int price = 0;
    double weight = 0.0;
    /* 
        scanf() - форматированный ввод
        Клавиатура -> Буфер входного потока stdin -> Запись значения в ячейку памяти через &(адрес переменной)
        Информация помещается в буфер 1 раз. Остальные вызовы scanf() тянут оставшиеся данные из буфера
        Модификатор %f принимает значения типа float. Для double используем %lf.
        Тип данных должен четко соответствовать модификатору !!!!!!!!!
        Модификатор * читает данные, но не записывает их из буфера в переменную

    */
    int res = scanf("%*llu; %u; %lf", &price, &weight);
    /*
        int res = scanf("%c%c", &byte1, &byte2);
        int res = scanf("%lld %lf", &var_lli, &var_d);
        int res1 = scanf("%c", &byte1);
        int res2 = scanf("%c", &byte2);
    */

    /* 
        printf() - форматированный вывод.
        Модификатор %f принимает значения типа double
    */
    printf("res = %d: price = %d, weight = %.2f\n", res, price, weight);

    return 0;
}