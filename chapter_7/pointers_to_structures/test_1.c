#include <stdio.h>
#include <stdlib.h>

// здесь объявляйте структуру
typedef struct tag_geom {
    char type;  // тип геометрической фигуры
    int x0, y0; // координаты верхнего левого угла
    int x1, y1; // координаты нижнего правого угла
} TAG_G;

int main(void)
{
    // здесь продолжайте функцию main
    TAG_G geom = {.type = '1', .x0 = 10, .y0 = 20, .x1 = 50, .y1 = 30};
    TAG_G* ptr_geom = malloc(sizeof(TAG_G));
    ptr_geom = &geom;
    printf("%c %d %d %d %d", ptr_geom->type, ptr_geom->x0, ptr_geom->y0, ptr_geom->x1, ptr_geom->y1);
    free(ptr_geom);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать)
    return 0;
}