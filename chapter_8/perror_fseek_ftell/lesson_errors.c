/*
    errno в языке C — это глобальная переменная, используемая для хранения кода ошибки,
        который возникает при выполнении системных вызовов или функций стандартной библиотеки.
    errno хранит код, расшифровку которого можно посмотреть в таблице 
    Функция perror() печатает описание последней ошибки
      
*/
#include <stdio.h>  // perror();
#include <errno.h>  // errno
 
int main(void)
{
    char buff[100];
 
    FILE* in = fopen("my_file.txt", "r");
    if(in == NULL) {
        //puts("File open error");
        printf("errno: %d\n", errno);
        perror("my_file.txt");
        return 1;
    }
 
    char ch;
    int i = 0;
    while((ch = fgetc(in)) != EOF)
        buff[i++] = ch;
    buff[i] = '\0';
 
    puts(buff);
 
    fclose(in);
    return 0;
}