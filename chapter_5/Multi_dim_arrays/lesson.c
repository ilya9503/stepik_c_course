/*
    Двумерные и многомерные массивы. Указатели на двумерные массивы

    Двумерные массивы - абстракция. В машинных кодах они являются одномерным массивом
    i - индекс строки, j - индекс столбца

    char game_pole[3][3];
    char y = game_pole[i][j];
            =
    #define N 3
    char pole_2[N * N]
    char x = pole_2[i * N + j]
*/

#include <stdio.h>

int main(void)
{
//    char game_pole[3][3] = {1, 2, 3, 4};
    char game_pole[5][3] = {{1, 2}, {3, 4}};

    /*   Указатель на двумерный массив как на одномерный   */
    char *p_row = game_pole[1]; // указатель ссылается на 0 эл-нт 1-ой строки

    char (*p_ar)[3] = game_pole;    // 
    char *ptr[3];                   // массив из 3-ех указателей

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j)
            printf("%d ", game_pole[i][j]);
        printf("\n");
    }

    size_t bytes = sizeof(game_pole);                               // размер всего массива в байтах
    size_t row_bytes = sizeof(game_pole[0]);                        // размер всей строки j в байтах
    size_t rows = sizeof(game_pole) / sizeof(game_pole[0]);         // количество строк i
    size_t cols = sizeof(game_pole[0]) / sizeof(game_pole[0][0]);   // количество столбцов j

    printf("bytes = %d, row_bytes = %d, rows = %d, cols = %d, *p_row = %d\n", bytes, row_bytes, rows, cols, *(p_row - 2));

    

    return 0;
}