#include <stdio.h>

int main(void)
{
    short var_1;
    int var_2;
    long long var_3;

    // здесь продолжайте программу
    scanf("%hd, %d, %lld", &var_1, &var_2, &var_3);

    int n = sizeof(short) + sizeof(int) + sizeof(long long);
    printf("%d\n", n);
    char ar[n];
    char *ptr_ar = ar;

    char *ptr_var_1 = (char*)&var_1;    // 2 байта
    char *ptr_var_2 = (char*)&var_2;    // 4 байта
    char *ptr_var_3 = (char*)&var_3;    // 8 байт

    
/*
    ptr_ar = ptr_var_1;
    ptr_ar += sizeof(short);
    ptr_ar = ptr_var_2;
    ptr_ar += sizeof(int);
    ptr_ar = ptr_var_3;
//    ptr_ar += 8;
*/
    for (int i = 0; i < n; ++i) {
        printf("%hhu ", *(ar + i));
    }
    

    return 0;
}