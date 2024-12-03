/*
    Собственный заголовочный файл func.h с прототипами функций
    Срабатывает при инициализации, только 1 раз. Когда еще не определено макроимя _FUNC_H__
    Делается это для защиты от повторного подключения заголовочного файла
        #include "func.h"
        #include "func.h"

*/

#ifndef _FUNC_H__
#define _FUNC_H__

double per_sq(double, double);
int abs_int(int x);
int sq_to_int(double x);

#endif