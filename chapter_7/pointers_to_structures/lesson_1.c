/*
    Пример возврата структур из функций
    Возврат структуры есть не что иное, как копирование всего ее содержимого в переменную bias
    Сама же переменная v перестает существовать после завершения функции create_vector()
    Если структура небольшого размера, то это не критично. Но если она занимает большие объемы, то возникает сразу две проблемы:
        Первая – это значительный расход ограниченной памяти стекового фрейма;
        Вторая – копирование большого объема памяти при возврате такой структуры из функции.
*/
#include <stdio.h>
#include <stdlib.h>

struct tag_vector { // Структура для представления двумерных радиус-векторов
    double x;
    double y;
};

// Функция формирования структуры struct tag_vector по переданным ей вещественным значениям
struct tag_vector create_vector(double x, double y)
{
    struct tag_vector v = {x, y};
    return v;
}

// Усовершенствованная функция create_vector, во избежании копирования большой структуры
struct tag_vector* create_vector_1(double x, double y)
{
    struct tag_vector* v = malloc(sizeof(struct tag_vector));
    v->x = x;
    v->y = y;
    
    return v;
}

// Функция сложения двух векторов
struct tag_vector sum_vector(const struct tag_vector* v1, const struct tag_vector* v2)
{
    struct tag_vector res = {v1->x + v2->x, v1->y + v2->y};
    return res;
}

int main(void) 
{
    struct tag_vector bias = create_vector(2.56, -7.88);
    printf("bias.x = %.2f, bias.y = %.2f\n", bias.x, bias.y);

    struct tag_vector* bias_1 = create_vector_1(2.56, -7.88);
    printf("bias.x = %.2f, bias.y = %.2f\n", bias_1->x, bias_1->y);
 
    free(bias_1);
 
    return 0;
}