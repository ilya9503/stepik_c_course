/*
    % - деление по модулю (остаток от деления)
    ++ - инкремент
    -- - декремент
*/
#include <stdio.h>
void parity_check();

int main(void)
{
/*
    // На знак результата влияет левый операнд
    int res_1 = -10 % 4;
    int res_2 = -10 % -4;
    int res_3 = 10 % -4;
    int res_4 = 10 - 10 / 4 * 4; // 10 - 2*4

 //   printf("%d", res_1);

    int digit;
//    scanf("%d", &digit);
//    parity_check(digit);

    int range = 10;         // [0; range-1]
    int res = digit % range;
//    printf("res = %d\n", res);

    unsigned int time = 4 * 3600 + 32 * 60 + 18;
    // часы : минуты : секунды
    unsigned int sec = time % 60;
    unsigned int min = (time / 60) % 60;
    unsigned int hour = time / 3600;

    printf("%02d:%02d:%02d\n", hour, min, sec);
*/
    int count = 0, size = 5;
    int current = count++;  // постфиксная форма. Сначала выполняется =, потом count++ (count = count + 1)
    int width = --size;     // префиксная форма. Сначала выполняется ++size, потом =

    int p = 2 * size++;     //  2 * 4 = 8
    int r = 3 * --width;    // 3 * (4 - 1) = 9

    printf("count = %d, size = %d, current = %d, width = %d\n", count, size, current, width);

    return 0;
}

// Проверка четности
void parity_check(int a)
{
    a = a % 2;
    if (a == 0) {
        printf("Число четное");
        return;
    }
        printf("Число нечетное");
}