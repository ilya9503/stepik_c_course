/*
    Строки в языке Си
    Типа данных строка не существует в Си
    Строка = массив символов + завершающий нуль
        т.е. количество элементов в массиве должно быть данные +1 символ
    Символы записываются в ОДИНАРНЫХ кавычках ''
    Строки записываются в ДВОЙНЫХ кавычках ""
    
*/
#include <stdio.h>

int main(void)
{
    // Инициализация строк
    char str[] = {'S', 'a', 'v', 'c', 'h', 'e', 'n', 'k', 'o', '\0'};

    char s[] = "Ilya Savchenko";

    char b[] = "Hel" "lo"
                ", World";
    
    char sp[] = "Hello, \
    World";

    /*
        Строковые литералы помещаются в неизменяемую область памяти (область текста)
        Массивы помещаются в стековый фрейм
            =
        Через указатель на строку можем только ЧИТАТЬ эту строку
        Через массив можем и ЧИТАТЬ и ПИСАТЬ
    */

    const char *str1 = "Savchenko";
    char s1[] = "Savchenko";

    //str[0] = 'A';
    s[0] = 'A';

    /*
        Механизм экранирования символов
    */
    char z[] = "I like programming in \"C\" language.";
    
    /* Writes the C string pointed by str to the standard output (stdout) and appends a newline character ('\n'). */
    puts(z);

    return 0;
}