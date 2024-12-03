/*
    Путь к определению прототипа можно прописать:
        1. В файле C:\Users\Илья\AppData\Roaming\Code\User\settings.json -->
            "c": "cd $dir && gcc -std=c99 $fileName func.c -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
        2. В заголовочном файле func.h
    Собственные заголовочные файлы пишутся в ковычках "func.h"
    Библиотечные заголовочные файлы пишутся в угловых скобках <func.h>
*/
#include <stdio.h>

//double per_sq(double, double);  // прототип функции

#include "func.h"   // тут содержится прототип, а в func.c лежит определение

int main(void)
{
    abs_int(-5);
    sq_to_int(-5.5);
    printf("per = %.2f\n", per_sq(2.5, 3.5));
    return 0;
}