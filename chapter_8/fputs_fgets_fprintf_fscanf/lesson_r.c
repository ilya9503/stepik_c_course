/*
    fgets() - Get string from stream
    char * fgets ( char * str, int num, FILE * stream );
        str - pointer to an array of chars where the string read is copied
        num - maximum number of characters to be copied into str (including the terminating null-character)
        stream -    Pointer to a FILE object that identifies an input stream.
                    stdin can be used as argument to read from the standard input.
        Return value - on success str. If error or EOF occurs, returns NULL-pointer
*/
#include <stdio.h>
#include <string.h>
 
int main(void)
{
   char buffer[100];   // буфер, куда будем записывать строки
 
    FILE* fp = fopen("my_file.txt", "r");   // открываем файловый поток на чтение
    if(fp == NULL) {    // обработка ошибки потока
        perror("my_file.txt");
        return 1;
    }
    /*  Читаем строки из файла в буффер, выводим по-строчно их на экран */
    while (fgets(buffer, sizeof(buffer), fp)) {
        // Находим и заменяем символ переноса строки на завершающий нуль
        char* ptr = strchr(buffer, '\n');
        if(ptr != NULL)
            *ptr = '\0';
        // Выводим строку на экран
        puts(buffer);
    }
    
    fclose(fp);
    return 0;
}