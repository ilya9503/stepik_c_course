/*
    Лучше использовать malloc, free чем массивы переменной длины
    sprintf() используется для преобразования чисел в строки

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    double w = 2.4, h = 0.76, d = 3.14;
    char name[] = "Chair";
    const size_t size = strlen(name) + 100;
    char *info = malloc(size);  /*Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.*/
    // malloc(), free()
    const char format[] = "(%s: %.2f x %.2f x %.2f)";

    sprintf(info, format, name, w, h, d);
    puts(info);

    free(info); /*Deallocate memory block*/

    return 0;
}