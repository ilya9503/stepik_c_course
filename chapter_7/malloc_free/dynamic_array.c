/*  Динамический массив */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Возврат - адрес без типа
    Массив data, длина массива, начальный размер массива, новое зн-е записываемое в массив
*/
void* append(short* data, size_t *length, size_t *capacity, short value)
{
    // Если длина увеличилась, создадим новый массив в 2 раза больше исходного
    if (*length >= *capacity) {
        //short *ar = malloc(sizeof(short) * 2 * *capacity);
        (*capacity) *= 2;
        short *ar = realloc(data, sizeof(short) * 2 * *capacity);

        if (ar == NULL) // проверка выполнения функции malloc
            return data;
        data = ar;
        /*
        (*capacity) *= 2;
        
        // скопируем содержимое старого массива в увеличенный
        memcpy(ar, data, *length * sizeof(short));

        
        for(int i = 0; i < *length; ++i)
            ar[i] = data[i];
        

        // освобождаем память старого массива, вызов malloc() в main
        free(data);
        data = ar;
        */
    }

    data[*length] = value;
    (*length)++;

    return data;
}

int main(void)
{
    size_t capacity = 10;   // начальный размер массива
    size_t length = 0;      // новый размер массива

    short *data = malloc(sizeof(short) * capacity);     // выделяем непрерывную область памяти под массив

    // добавляем новые значения в массив data (11 новых значений)
    for (int i = 0; i < 11; ++i)
        data = append(data, &length, &capacity, rand() % 40 - 20);

    printf("length = %u, capacity = %u\n", length, capacity);

    // выводим новый массив на экран
    for(int i = 0; i < length; ++i)
        printf("%d ", data[i]);
    
    free(data);

    return 0;
}