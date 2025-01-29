/*
    Требуется записать строки из массива в файл myfile.txt в формате
        8 (917) 123-45-67
    Используем функцию fprintf() - форматный вывод данных в указанный поток

    fprintf - Write formatted data to stream
    int fprintf ( FILE * stream, const char * format, ... );

*/
#include <stdio.h>
 
int main(void)
{
    // 1-ая размерность - номер телефона, 2-ая размерность - составляющие номера 
    const char* phones[][5] = {
        {"8", "917", "123", "45", "67"},
        {"8", "904", "123", "45", "68"},
        {"8", "906", "123", "45", "69"}
    };

    FILE* fp = fopen("my_file.txt", "w");
    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    for(int i = 0; i < sizeof(phones) / sizeof(*phones); ++i)
        fprintf(fp,"%s(%s)%s-%s-%s\n", phones[i][0], phones[i][1], phones[i][2],
                                    phones[i][3], phones[i][4], phones[i][5]);
 
    fclose(fp);
 
    return 0;
}