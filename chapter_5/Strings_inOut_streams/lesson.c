#include <stdio.h>  // puts(), fgets(), stdin

int main(void)
{
    char sp[] = "Hello, World!";
    char bf[10];
    /*
        Вывод строк
        puts() автоматически добавляет \n
    */ 
    printf("sp = %s\n", sp);
    puts(sp);

    /*=========================================================================
        Ввод строк
        1.  scanf() отсутствие амперсанда
            Нужно указывать максимальную ширину чтения, без учета \0
            Ограничивать зону чтения в буфер
            НЕУДОБНЫЙ ВАРИАНТ
        2. char* gets(char* buf) УЯЗВИМА - НЕЛЬЗЯ использовать со строками

    */
    //scanf("%9s", bf);    // НЕНАДЕЖНЫЙ вариант для ввода строк

    /*
    fgets(char*str, int num, FILE * stream)
        str - Pointer to an array of chars where the string read is copied.
        num - Maximum number of characters to be copied into str (including the terminating null-character).
        stream - Pointer to a FILE object that identifies an input stream.
                stdin can be used as argument to read from the standard input.
    
    !! Автоматически добавляет в вводимую строку символ перевода строки \n

    */
    fgets(bf, sizeof(bf), stdin);   // безопасный вариант чтения строк №1

    /*
        Безопасный вариант чтения строк №2
        Самописный через множественный вызов getchar()
    */
    int max_len = sizeof(bf), i = 0;
    char *ptr = bf, ch;

    while ((ch = getchar()) != '\n' && ch != EOF && i < max_len-1)
        ptr[i++] = ch;

    ptr[i] = '\0';

    puts(bf);



    return 0;
}