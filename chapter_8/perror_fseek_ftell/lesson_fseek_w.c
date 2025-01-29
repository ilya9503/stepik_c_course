#include <stdio.h>
 
int main(void)
{
    char str[] = "Function fputc() in action.";
 
    FILE* fp = fopen("my_file_2.txt", "w");
    if(fp == NULL) {
        perror("my_file_2.txt");
        return 1;
    }
 
    for(int i = 0; str[i]; ++i) {
        fseek(fp, 0, SEEK_SET); //  последовательно запишет символы в файл, но в 
                                //  одну позицию. Если подставить i, запишет полностью
        fputc(str[i], fp);
    }
 
    fclose(fp);
    return 0;
}