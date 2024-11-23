/*
    Продолжите программу. Определите в строке str количество фрагментов 'is'
    и выведите в консоль полученное целое число.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {"My sister is a nervous girl, but she is very kind."};
//    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте программу
    char substr[] = "is";
    char *ptr_sub;  // указатель на символ! НЕ на строку

    int i = 0;
    ptr_sub = str;  // указатель на 1-ый символ массива

    while (ptr_sub != NULL) {
        ptr_sub = strstr(ptr_sub, substr);
        if(ptr_sub != NULL) {
            ++ptr_sub;  // Возвращает указатель на подстроку "is", поэтому +1 перемещает на 2 символа
            ++i;
        }
    }

    printf("%d", i);

    return 0;
}