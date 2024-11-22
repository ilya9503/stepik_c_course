/*  Программа сравнения 2 строк    */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[12] = "Hello";
    char s2[10] = "Hello";

    const char *str1 = s1;  // константный указатель ЗНАЧЕНИЕ которого менять НЕЛЬЗЯ (VALUE READ-ONLY)
    const char *str2 = s2;

    int i = 0;
    for ( ; str1[i] != '\0' && str2[i] != '\0'; ++i)
        // Поочередно сверяем символы
        if (str1[i] != str2[i]) {
            puts("Strings are not equal!");
            return 0;
        }
    
    // Если последние символы не равны \0, то длины отличаются
    if (str1[i] != str2[i]) {
        puts("String lengths are not equal!");
        return 0;
    }

    puts("Strings are equal!");
    
    return 0;
}