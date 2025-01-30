/*
    Результат смотреть в файле myfile.txt
    В бинарном режиме размер файла 13 байт
*/

#include <stdio.h>
 
int main(void)
{
    int var_i = -10;
    double pi = 3.141592653589793;
    char ch = 'S';
 
    FILE* fp = fopen("my_file.txt", "w");
    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    //fprintf(fp, "%d; %f; %c\n", var_i, pi, ch);   // запись чисел в текстовом режиме
    fwrite(&var_i, sizeof(var_i), 1, fp);   // запись чисел в бинарном режиме
    fwrite(&pi, sizeof(pi), 1, fp);
    fwrite(&ch, sizeof(ch), 1, fp);

    fclose(fp);
 
    return 0;
}