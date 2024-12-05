#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 20

int get_data_csv(double *ar, int length, const char* str)
{
    int i = 0;
    char* ptr = strchr(str, ':');
    ptr++;
    for( ; ptr != NULL && i < length ; ++i) {
        ar[i] = atof(ptr);
        ptr = strchr(ptr, ';');
        if(ptr != NULL)
            ptr++;
    }
    return i;
}

int main(void)
{
    char str[100] = {0};
//    strcpy(str, "csv: 0.56; -65.43; 0.1; 11.0");
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    
    // здесь продолжайте функцию main
    double ar[NUM] = {0};
    int count = get_data_csv(ar, NUM, str);

    for(int i = 0; i < count ; ++i)
        printf("%.2f ", ar[i]);

    return 0;
}