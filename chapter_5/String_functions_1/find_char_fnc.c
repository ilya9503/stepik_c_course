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
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Abrakadabra";     // Исходная строка
    char *ptr = strchr(str, 'a');   // Указатель на адрес первого попавшегося символа 'a' Ищет с начала строки
//    char *ptr = strrchr(str, 'a');
//    char *ptr = strrchr(str, 'a');    

    printf("str = %p\nptr = %p\n", str, ptr);

    if (ptr != NULL)
        printf("ptr - str = %p\n*ptr = %c\n", ptr - str, *ptr);
    
    

    return 0;
}