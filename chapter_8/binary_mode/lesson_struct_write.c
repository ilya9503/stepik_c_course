/*
    Пусть у нас в программе объявлена структура и в файл нужно сохранить массив из этих структур
*/
#include <stdio.h>
 
enum {name_size=10};
 
typedef struct
{
    char name[name_size];
    double x, y;
} POINT;
 
int main(void)
{
    POINT fig[] = {     // массив структур POINT
        {"Point 1", 0.0, 0.0},
        {"Point 2", 4.23, -21.0},
        {"Point 3", 6.65, -31.34},
        {"Point 4", 3.2, -44.62},
        {"Point 5", -1.65, 1.0},
    };
 
    FILE* fp = fopen("my_file.txt", "wb");  // открываем файл на запись в бинарном режиме
    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
    // Вернет количество записанных в файл элементов
    int res = fwrite(fig, sizeof(POINT), sizeof(fig) / sizeof(*fig), fp);
    fclose(fp);
 
    printf("res = %d\n", res);
 
    return 0;
}