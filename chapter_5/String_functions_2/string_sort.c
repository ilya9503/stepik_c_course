/*
    Продолжите программу. В массиве строк str хранится информация о count товарах, каждый представлен в формате:

    <наименование товара>: <идентификатор>; <цена>; <вес>

    Здесь идентификатор - целое число; цена - целое число; вес - вещественное число. 

    Необходимо массив указателей p_sort сформировать так, чтобы они ссылались на отсортированные строки
    по убыванию веса товара. (Сортировку лучше выполнять непосредственно массива p_sort.)

    Выведите в консоль в одну строчку через пробел наименования товаров, отсортированные по убыванию веса товара.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL   10

int main(void)
{
    char str[TOTAL][50] = {0};
    char *p_sort[TOTAL];
    int count = 0;

    while(count < TOTAL && fgets(str[count], sizeof(str)-1, stdin)) {
        char* ptr_n = strrchr(str[count], '\n');
        if(ptr_n != NULL)
            *ptr_n = '\0';
        count++;
    }

    // здесь продолжайте программу
    for(int i = 0; i < count; ++i)  // массив указателей для сортировки
        p_sort[i] = str[i];

    /*  Сортировка
        Перебираем массив p_sort[i] */
    int pos = 0;
    for (int i = 0; i < count-1; ++i) {
        pos = i;
        // Выбираем MAX индекс массива
        for (int j = i+1; j < count; ++j) {
            double WeightCur =  atof(strrchr(p_sort[pos], ';') + 1);    // вес текущей строки
            double WeightNext = atof(strrchr(p_sort[j], ';') + 1);      // вес следующей строки
            if(WeightCur < WeightNext)                                  // сравниваем, сдвигаемся вправо
                pos = j;
        }
        // Если MAX в любой другой ячейке, то меняем ее с текущей
        if(pos != i) {
            // Меняем эл-ты местами
            char *p_temp = p_sort[i];
            p_sort[i] = p_sort[pos];
            p_sort[pos] = p_temp;
        }
    }

    for(int i = 0; i < count; ++i) {
        char *ptr = strchr(p_sort[i], ':');         // ищем наименование товара
        char name[20] = {0};
        strncpy(name, p_sort[i], ptr-p_sort[i]);    // вырезаем и выводим наименование товара
        printf("%s ", name);
    }

    return 0;
}