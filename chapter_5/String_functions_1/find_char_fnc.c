/*  
    Функции поиска символов в строке:
    char* strchr(const char* str, int val)
        Выполняет поиск символа слева-направо с кодом val в строке str
    char* strrchr(const char* str, int val)
        Выполняет поиск символа справа-налево с кодом val в строке str

    Функции поиска подстроки в строке:
    char* strstr(const char* str, const char* find)
        Выполняет поиск слева-направо подстроки find в строке str
    char* strpbrk(const char* str, const char* find)
        Выполняет поиск слева-направо любого символа из подстроки find в строке str

    strchr – string character (поиск первого вхождения символа в строке).

    strrchr – string reverse character (поиск последнего вхождения символа в строке).

    strstr – string string (поиск подстроки в строке).

    strpbrk – string pointer break (поиск первого из множества символов в строке).
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Abrakadabra";     // Исходная строка
//    char *ptr = strchr(str, 'a');   // Указатель на адрес первого попавшегося символа 'a' Ищет с начала строки
//    char *ptr = strrchr(str, 'a');
    char *ptr = strstr(str, "ra");    

    printf("str = %p\nptr = %p\n", str, ptr);

    if (ptr != NULL)
//        printf("ptr - str = %p\n*ptr = %c\n", ptr - str, *ptr);
        printf("ptr = %s\n", ptr);
    
    

    return 0;
}