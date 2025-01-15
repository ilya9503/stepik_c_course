/*
    Константы времени компиляции - значения констант формируются в момент компиляции программы:
        Тип данных - перечисление
    Константы времени выполнения
        
    От константных переменных их отличает то, что их значения формируются в момент компиляции программы, то есть, они являются константами времени компиляции
    –Wall (отображение всех предупреждений) в settings.json

// In both of the below cases, "day" is 
// defined as the variable of type week. 

enum week{Mon, Tue, Wed};
enum week day;

// Or

enum week{Mon, Tue, Wed}day;    
*/

#include <stdio.h>

#define RED         1
#define GREEN       1
#define BLUE        1

enum colors {red, green, blue} wnd_colors;                 // без инициализации преобретают значения типа int 0, 1, 2...
enum keys {vk_enter=27, vk_space, vk_del=30};
enum {
    go = 0x1f00, 
    stop = 0x0001, 
    forward = go,
    run = 0x00a2,
    back = run -1
} actions, commands;

int main(void)
{
    enum keys k_var = vk_space;     // int

    // При перечислении case указывать все указанные в {} константы
    switch(k_var) {
    case vk_enter:
        puts("vk_enter");
        break;
    case vk_space:
        puts("vk_space");
        break;
    case vk_del:
        puts("vk_del");
        break;
    }

    printf("red = %d, green = %d, blue = %d\n", red, green, blue);
    return 0;
}