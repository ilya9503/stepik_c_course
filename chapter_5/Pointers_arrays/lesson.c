#include <stdio.h>

int main(void)
{
    short ar[] = {4, 3, 2, 1, 5, 6, 7};
    short *ptr_ar;

    // Одно и то же
    ptr_ar = ar;
//    ptr_ar = &ar[0];

    short x = *ptr_ar;
    *(ptr_ar+1) = -3;

    size_t len_1 = sizeof(ar);      // 2 * 7 = 14 байт. ar - указатель на массив
    size_t len_2 = sizeof(ptr_ar);  // 4 байт (размер самого указателя, тип int).
    /*
        ptr_ar - обычный указатель, можно менять адрес
        ar - указатель на массив. Адрес менять запрещено!!
    */

    short x = ptr_ar[2];    // ar[index] = *(ar + index)
    short y = 2[ptr_ar];    // одно и то же

    /*
        Размер массива в байтах / размер 1-ого элемента в байтах = кол-во эл-тов массива
        Указатель со скобками ar[index] = *(ar + index)
    */
    for (int i = 0; i < sizeof(ar) / sizeof(*ar); ++i) {
        printf("%d ", *(ar+i));
    }

    printf("\n");
    printf("%d %d\n", len_1, len_2);


    return 0;
}