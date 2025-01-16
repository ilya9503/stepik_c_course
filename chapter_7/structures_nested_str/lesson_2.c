/*
    Получился довольно оригинальный способ работы с массивами. Хотя на практике так не делают.
    Объявлять структуру с массивом только ради возможности его копирования, не лучший ход.
    Если уж нам действительно так важно быстро перенести данные из одного массива в такой же другой,
        то для этого можно воспользоваться функцией:
        void* memcpy(void* restrict dst, const void* restrict src, size_t length);
*/
#include <stdio.h>

enum {name_length=50, b_length=20};

struct tag_array {
    int marks[b_length];
};
 
int main(void) 
{
    struct tag_array marks_1 = {2, 2, 2, 3, 2, 2};
    struct tag_array marks_2;
 
    marks_2 = marks_1;  // копируем массив marks_1 в массив marks_2 присваиванием. Работает только со структурами
    for(int i = 0;i < sizeof(marks_2.marks) / sizeof(*marks_2.marks); ++i)
        printf("%d ", marks_2.marks[i]);
        
    return 0;
}