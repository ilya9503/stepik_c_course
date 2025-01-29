/*
    int fseek(FILE* stream, long offset, int whence);   позволяет задавать файловую позицию
        stream - объект файлого потока
        offset - смещение относительно whence
        whence - откуда, принимает значения:
            SEEK_SET – от начала файла;
            SEEK_CUR – от текущей позиции;
            SEEK_END – от конца файла.
    long ftell(FILE* stream);   позволяет получать значение файловой позиции
*/

#include <stdio.h>  // fseek(), ftell()
 
int main(void)
{
    FILE* fp = fopen("my_file.txt", "r");   // открываем файл на чтение
    if(fp == NULL) {
        perror("my_file.txt");
        return 1;
    }
 
    fseek(fp, 0, SEEK_END);     // установим файловую позицию в конец файла
    int length = ftell(fp);     // позиция в конце файла -> ftell() вернет общее число байт в файле
    
    printf("Length of the string: %d\n", length);

    /*  Читаем содержимое файла в обратном порядке  */
    for (int i = 1; i <= length; ++i) {
        // -i здесь это оператор отрицания, то есть i станет не 1, а -1 и тд
        fseek(fp, -i, SEEK_END);    // начиная с конца файла декрементируем позицию -1 -2 -3 -4...
        putchar(fgetc(fp));         // побайтный вывод на экран
    }
    
    putchar('\n');
 
    fclose(fp);
    return 0;
}