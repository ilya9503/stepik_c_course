//6.6.6
#include <stdio.h>
#include <string.h>


void strip_str(char str[], char del_symb[])
{
    char *ptr;
    while(ptr = strpbrk(str, del_symb)){
        strcpy(ptr, ptr + 1);       // Урезаем содержимое указателя на 1 символ и переприсваиваем. Гениально!
    }
}

int main(void)
{
    char str[100] = {"Hello, World!"};
    /*
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if(ptr_n)
        *ptr_n = '\0';
    */
    char del_symb[] = ".,-!?";
    strip_str(str, del_symb);
    puts(str);
    return 0;
}