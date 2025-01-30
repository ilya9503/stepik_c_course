/*
    Flush stream
    int fflush ( FILE * stream );
    If the given stream was open for writing
        (or if it was open for updating and the last i/o operation was an output operation)
            any unwritten data in its output buffer is written to the file.
    The stream remains open after this call.
    Return Value
        A zero value indicates success.
        If an error occurs, EOF is returned and the error indicator is set
    Нужно применять к выходному потоку, а не к входному

    Схема записи данных в поток:
        Данные --> Выходной буфер --> Файл


*/
#include <stdio.h>
 
int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, -1};   // в файл будем заносить и считывать эти данные
    int length = sizeof(data) / sizeof(*data);
 
    FILE* fp = fopen("write_and_read.dat", "w");    // открываем файл на запись и чтение (создастся)
    FILE* in = fopen("write_and_read.dat", "r");

    if(fp == NULL || in == NULL) {
        perror("write_and_read.dat");
        return 1;
    }
 
    for(int i = 0;i < length;++i)
        fprintf(fp, "%d ", data[i]);    // записывает данные в выходной поток через промежуточный буфер
 
    fflush(fp);     // Переносит оставшиеся в буфере данные в файл, поток остается открытым
    // fclose(fp)   // Можно вместо fflush закрыть поток, данные из буфера так же перенесутся
 
    int value;      // Читаем данные из файла и выводим в консоль
    for(int i = 0;i < length;++i)
        if(fscanf(in, "%d ", &value) == 1)
            printf("%d ", value);
 
    fclose(fp);
    fclose(in);
 
    return 0;
}