/*
    Вариадические функции - с произвольным количеством параметров
    Заголовок stdarg.h описывает:
        va_start() – для получения указателя на первый вариадический параметр функции (тот, что идет после параметра count в нашем примере);
        va_arg() – для получения значения текущего параметра и переход к следующему вариадическому параметру;
        va_end() – для завершения процедуры перебора (это необходимо, если потребуется новый обход параметров, тогда нужно будет снова вызвать
        va_start() и va_arg() для извлечения значений).
    В момент вызова какой-либо функции, все аргументы, указанные при ее вызове, автоматически копируются во фреймовый стек, начиная с последнего.
    ОЧЕНЬ редко используются на практике
*/
#include <stdio.h>
#include <stdarg.h> // определяет вариадические функции
 
int sum(int count, ...)
{
    int s = 0;
    va_list arg;                // указатель на параметр
    va_start(arg, count);       // получение адреса первого вариадического параметра 
    for(int i=0; i < count; ++i) {
        s += va_arg(arg, int);  // получение значение вариадического параметра
                                // и переход к следующему параметру
    }
    va_end(arg);                // завершение процедуры перебора вариадических параметров
    return s;
}
 
 
int main(void) 
{
    int res = sum(5, 1, 2, 3, 4, 5);
    printf("res = %d\n", res);
 
    return 0;
}