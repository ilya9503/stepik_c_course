#include <stdio.h>
#include <stdbool.h>    // добавляет замену _Bool на bool. Добавляет ключевые слова true/false

int main(void)
{
    _Bool a = 0;    // Тип стандарта C99. _Bool = char = 1 байт. 0 - false, 1 - true. У типа int, char 0 - false, любое другое зн-е true
    a = 10;         // будет приведен к значению 1

    bool b = true;  // Появляется после подключения заголовка
//    printf("Size of _Bool = %d %d\n", sizeof(_Bool), a);

    double x = 5.67;
    int var_i = 7;

    bool fl_view = x < 10;
    bool res_1 = 5 > 7;
    bool res_2 = x + 2 >= 10.56;
    bool res_3 = var_i == 7;    // только целые числа!
    bool res_4 = var_i != 7;

//    printf("%d\n", fl_view);

    int digit;

//    scanf("%d", &digit);

    bool even = digit % 2 == 0; // сначала вернется остаток, затем сравнение
//    printf("%d\n", even);

    double y = 10.86;
    bool is_range = y >= -2 && y <= 5;      // 
    bool is_not_range = ! is_range;         // y < -2 || y > 5
 //   printf("%d\n", is_range);

    int z = 15;
    bool is_correct = z % 2 == 0 || z % 3 == 0 && z > 5;    // 1. && 2. || 3. =
// Все проверки проходят слева на право. Сначала проверяется 1 подусловие, затем второе (в зависимости от операции)
    printf("%d\n", is_correct);
    bool zero_test = z != 0 && 10 / x > 1;

    return 0;
}