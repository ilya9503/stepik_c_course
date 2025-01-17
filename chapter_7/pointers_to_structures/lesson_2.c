/*

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tag_vector { // Структура для представления двумерных радиус-векторов
    double x;
    double y;
} VECTOR;

// Функция формирования структуры struct tag_vector по переданным ей вещественным значениям
VECTOR create_vector(double x, double y)
{
    //VECTOR v = {x, y};
    //return v;
    return (VECTOR) {x, y};
}

/*
    Функция сложения двух векторов
        Указатели у параметров ускоряют работу со структурами.
        Если указывать как обычные аргументы, они будут копироваться полностью, что замедляет работу программы
        Копирование указателей (адресов) происходит в разы быстрее
*/
VECTOR sum_vector(const VECTOR* v1, const VECTOR* v2)
{
    //VECTOR res = {v1->x + v2->x, v1->y + v2->y};
    //return res;
    return (VECTOR) {v1->x + v2->x, v1->y + v2->y};
}

// Функция суммирует 2 структуры в 1-ой структуре
void isum_vector(VECTOR* v1, const VECTOR* v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
}

int main(void) 
{
    VECTOR bias = create_vector(2.56, -7.88);
    VECTOR one = create_vector(1.0, 1.0);
    VECTOR result = sum_vector(&bias, &one);
    isum_vector(&bias, &one);
    isum_vector(&bias, &(VECTOR) {0.5, -0.5});

    printf("bias.x = %.2f, bias.y = %.2f\n", bias.x, bias.y);
 
    return 0;
}