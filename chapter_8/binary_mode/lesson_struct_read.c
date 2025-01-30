/*
    Читаем структуры из файла
*/
#include <stdio.h>
 
enum {name_size=10, max_points=50};
 
typedef struct
{
    char name[name_size];
    double x, y;
} POINT;
 
int main(void)
{
    POINT fig[max_points];
    int length = 0;
 
    FILE* fp = fopen("my_file.txt", "rb");
    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    while(fread(&fig[length], sizeof(POINT), 1, fp) == 1)   // читаем поэлементно в массив fig
        length++;
 
    fclose(fp);
 
    for(int i = 0;i < length; ++i)
        printf("%s: (%.2f, %.2f)\n", fig[i].name, fig[i].x, fig[i].y);
 
    return 0;
}