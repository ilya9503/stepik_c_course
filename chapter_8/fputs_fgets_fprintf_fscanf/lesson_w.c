/*
    fputs - Write string to stream
    int fputs ( const char * str, FILE * stream );
        str - C string with the content to be written to stream
        stream - Pointer to a FILE object that identifies an output stream
        Return value:
            On success, a non-negative value is returned.
            On error, the function returns EOF and sets the error indicator (ferror).
            EOF (End-of-File) - It is a macro definition of type int that expands into a negative integral
                constant expression (generally, -1).
*/
#include <stdio.h>
 
int main(void)
{
    const char* str[] = {   // массив строк (указателей на строки)
        "- Скажи-ка, дядя, ведь не даром",
        "Я Python, Си учил с каналом",
        "Балакирев что раздавал?"
    };
 
    FILE* fp = fopen("my_file.txt", "w");   // открываем файловый поток на запись
    if(fp == NULL) {    // обработка ошибки потока
        perror("my_file.txt");
        return 1;
    }
 
    for(int i = 0;i < sizeof(str)/sizeof(*str); ++i) {
        fputs(str[i], fp);  // по строчно записывает символы в файл
        fputc('\n', fp);
    }
    fclose(fp);
    return 0;
}