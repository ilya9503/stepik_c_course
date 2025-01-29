/*
    Check end-of-file indicator
    int feof ( FILE * stream );
    Возвращает 0 если конец файла не достигнут и 1 если достигнут
*/
#include <stdio.h>
 
enum {max_length=100};
 
int main(void)
{
    double data[max_length];    // вещественные данные
    char buffer[max_length];    // заголовки из файла csv
    int length = 0;
 
    FILE* fp = fopen("data_rubusd2.csv", "r");  // открываем файл на чтение
    if(fp == NULL) {
        perror("data_rubusd2.csv");
        return 1;
    }
 
    while(!feof(fp)) {  // feof() возвращает 0 если конец файла не достигнут и 1 если достигнут
        fgets(buffer, sizeof(buffer), fp);  // читаем строковый заголовок в файле csv
 
        length = 0;     // читаем всю строку с вещественными данными
        while(fscanf(fp, "%lf ; ", &data[length]) == 1)
            length++;
 
        puts(buffer);
        for(int i = 0;i < length;++i)
            printf("%.2f ", data[i]);
        putchar('\n');
    }
 
    fclose(fp);
    return 0;
}