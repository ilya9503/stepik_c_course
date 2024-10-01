#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* Математические функции */

int main (void)
{
    /*
        Генерация псевдослучайных величин rand()
        Вычисляются по некоторому алгоритму, поэтому псевдослучайные
        Распределены по равномерному закону в диапазоне [0; RAND_MAX]
            RAND MAX >= 32767

        srand() - инициализация генератора псевдослучайных чисел.
            Аргумент каждый вызов должен быть разным для получения рандомных чисел
            Для этого в качестве аргумента добавляем метку времени

        Пример генерации для требуемого диапазона:
        v1 = rand() % 100;         // v1 in the range 0 to 99
        v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
        v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014


        
    */
//    time_t t = time(NULL);

    srand(time(NULL));

    int range = 10;

    int r_1 = rand() % range;       // [0; range)
    int r_2 = rand() % range - 5;   // [-5; range -5)
    int r_3 = rand() + rand();

    // Если требуется генерировать вещественные числа в диапазоне от 0 до 1
    double range_float = ((double)rand() / (double)RAND_MAX) * 100.0;     // [0; 1]

    printf("%d, %d, %.2f\n", r_1, r_2, range_float);

    return 0;
}