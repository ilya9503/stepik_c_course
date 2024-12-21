#include <stdio.h>
#define MAX_LENGTH    20

size_t to_flat(short* v,    /* массив, в который заносятся значения */
        size_t max_len_v,   /* максимальная длина массива v */
        short* table[],     /* массив на массив, из которого читаются значения */
        size_t len,         /* длина массива table (первая размерность) */
        size_t count_v,     /* число записанных в массив v значений (начальное значение 0) */
        size_t indx_t,      /* индекс для перебора указателей (первой размерности) массива table (начальное значение 0) */
        size_t indx)        /* индекс для перебора элементов массивов (условно, вторая размерность), 
                                на которые ссылается текущий указатель table[indx_t] (начальное значение 0)*/
{
    // Перебираем массив, в который заносятся значения
    indx_t = 0;                 // 1-я размерность table
    while(indx_t < len) {
        indx = 0;               // 2-я размерность table
        while(table[indx_t][indx] != 0) {
            *v = table[indx_t][indx];
            ++v;
            ++indx;
            ++count_v;
        }
    ++indx_t;
    }
    return count_v;
}

int main(void)
{
    short ar_1[] = {-4, 2, 3, 7, 0};
    short ar_2[] = {11, 6, 10, 8, 13, 98, -5, 0};
    short ar_3[] = {-47, 0};
    short ar_4[] = {8, 11, 56, -3, -2, 0};

    short * table[] = {ar_1, ar_4, ar_3, ar_2};

    short flat[MAX_LENGTH];

    size_t cnt = to_flat(flat, MAX_LENGTH, table, sizeof(table) / sizeof(*table), 0, 0, 0);

    for(int i = 0;i < cnt; ++i)
        printf("%d ", flat[i]);
//    printf(" cnt = %d", cnt);

    return 0;
}