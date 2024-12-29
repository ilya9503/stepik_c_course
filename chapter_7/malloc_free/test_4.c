#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL   10

// здесь объявляйте функцию

/*
    Возврат - адрес для пустого типа данных (может быть переназначен любой)
    ptr - исходный массив
    len - длина исходного массива
    fill - значение для заполнения новых ячеек массива
*/

void* expand_array(short* ptr, size_t* len, short fill)
{
    size_t len_new = (*len) * 2;    // увеличиваем исходный размер области памяти в 2 раза
    size_t len_old = (*len);

    short *ptr_new = realloc(ptr, sizeof(*ptr) * len_new);  // меняем адрес и размер исходной области памяти
    if(ptr_new == NULL) // проверка realloc()
        return ptr;

    memcpy(ptr_new, ptr, len_old);  // копируем старые данные в новый блок

    while(len_old <= len_new) {   // заполняем оставшиеся ячейки массива значением fill
        ptr_new[len_old] = fill;
        ++len_old;
    }
    (*len) *= 2;

    return ptr_new;
}

int main(void)
{
   short * ptr_d = calloc(TOTAL,  sizeof(short));
   size_t len = TOTAL;
   if(ptr_d == NULL)
        return 0;

    int count = 0;
    
    while(count < TOTAL && scanf("%hd", &ptr_d[count]) == 1)
        count++;
    
    // здесь продолжайте функцию main
    ptr_d = expand_array(ptr_d, &len, -1);

    for(int i = 0; i < len; ++i)
        printf("%hd ", ptr_d[i]);

    free(ptr_d);
    return 0;
}