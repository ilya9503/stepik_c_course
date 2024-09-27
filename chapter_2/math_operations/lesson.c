#include <stdio.h>
int glob = 5;

int main(void)
{

    short a = -5;
    int b = 10;
    float c = 5.4f;
    double d = -6.5;

    int res_1 = a + b;
    short res_2 = 100 - b;
    float res_3 = 5.4 - c;
    double res_4 = d * 4;

    /*
        При делении целое/целое получается целое
        При понижении типов может быть потеря данных

    */
    int res_5 = 7 / 2;          // 3
    double res_6 = -9 / 2;      // -4
    float res_7 = a / c;        // -0.92592591
    double res_8 = d / b;       // -0.65..

    // Приведение типов
    double res_9 = (double)a / (double)b;
    double res_10 = 7.0 / 2.0;

    // Унарная операция имеет приоритет над бинарной
    int res_11 = 10 + -7;

    return 0;
}