/*
    Считаем данные из файла csv с помощью функции fscanf
    Работает аналогично scnaf, только с потоками (в том числе с файловым)
    fscanf - форматное чтение данных из указанного потока
    fscanf - Read formatted data from stream
    int fscanf ( FILE * stream, const char * format, ... );
*/
#include <stdio.h>
 
enum {max_length=1024};
 
int main(void)
{
    double rub_usd[max_length] = {0.0}; // массив, куда будем читать данные из файла csv
    unsigned length = 0;                // кол-во прочитанных из файла данных
 
    FILE* fp = fopen("data_rubusd.csv", "r");   // открываем файл на чтение

    if(fp == NULL) {
        perror("data_rubusd.csv");
        return 1;
    }
 
    while(fscanf(fp, "%lf ; ", &rub_usd[length]) == 1)   // fscanf возвращает 1, если данные прочитаны корректно
        length++;   // постфикс, 0, 1, 2, 3 ...
 
    fclose(fp);
 
    for(int i = 0; i < length; ++i)
        printf("%.3f ", rub_usd[i]);
 
    return 0;
}