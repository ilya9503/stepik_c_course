#include <stdio.h>
/*  так же добавим имя файла module.c в settings.json, для правильной сборки проекта    */
extern int global_var;          // описание, где находится переменная. Не является объявлением переменной
extern char global_str[];       // тип и имя переменной
extern int global_seed_randint; // нельзя ссылаться на static переменную

int randint(int, int);  // прототип функции похож по функционалу на extern

int main(void)
{
    int a = 1, b = 10;
    printf("%d\n", global_seed_randint);
    printf("%d\n", randint(a, b));
    printf("%d\n", randint(a, b));
    printf("%d\n", randint(a, b));
/*
    printf("global_var = %d\n", global_var);
    printf("global_var = %s\n", global_str);
*/
    return 0;
}

char global_str[100] = "Hello";