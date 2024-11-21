#include <stdio.h>
#include <string.h>
#define N 7
#define LENGHT 50

int main(void)
{
    // здесь продолжайте программу
    int err;
    char ps[N][LENGHT] = {{"Ivanov"}, {"Petrova"}, {"Sidorova"}, {"Balakirev"}, {"Bach"}, {"Stras"}, {"Lomonosova"}};

    char ps_sort[(N+1)*LENGHT] = {0};
    char *ptr_res = ps_sort;
    /*
   for (int i = 0; i < N; i++) {
        if ((err=scanf("%s ", ps[i])) != 1) {
            printf("Error input! - %d\n", err);
            return 0;
        }
    }
    */

    /*   
        Сравнивает каждое число длины строки [0-49],
        с фактической длиной каждой строки.
        Таким образом сортирует с самого меньшего до наибольшего
    */
    for(int l=0; l<LENGHT; l++) {
        for (int i = 0; i < N; i++) {
            if (strlen(ps[i]) == l ) {
                strcat(ptr_res, ps[i]);
                strcat(ptr_res, " ");
            }
        }
    }
    ps_sort[strlen(ps_sort)-1] = 0;
    printf("%s\n", ptr_res);
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
} 