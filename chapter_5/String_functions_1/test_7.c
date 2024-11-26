/*
    Напишите программу, которая читает из входного потока время, представленное в виде строки формата:
    hh:mm:ss
    где hh - часы; mm - минуты; ss - секунды. Например:
    12:06:30
    Необходимо преобразовать эту строку и представить время в формате:
    ss:mm:hh
    Полученную строку вывести в консоль.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {"15:24:10"};
/*
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
*/
    // читаем исходный формат hh:mm:ss в str
    printf("Initial string %s\n", str);

    char *ptr_hh, *ptr_ss;
    char res[100] = {0};            // строка с результатом

    ptr_ss = strrchr(str, ':');     // ищем ":ss"
    if(ptr_ss != NULL) {
        strcat(res, ptr_ss+1);      // ss
        strcat(res, ":");           // :
    }

    
    ptr_hh = strchr(str, ':');      // ищем ":mm:ss"
    if(ptr_hh != NULL) {
        strncat(res, ptr_hh+1, 2);  // mm
        strcat(res, ":");           // :           
        strncat(res, str, 2);       // hh
    }

    printf("Resulting string %s\n", res);

/*  Хотя, вот так, конечно, проще. И с данными о времени можно что-то делать.
    
    scanf("%02d:%02d:%02d", &hh, &mm, &ss);
    printf("%02d:%02d:%02d", ss, mm, hh);
*/


    return 0;

}