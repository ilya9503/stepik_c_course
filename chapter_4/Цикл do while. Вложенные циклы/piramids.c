/*
    Сделать пирамидку из звездочек
*/
#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Incorrect input!");
        return 0;
    }

    // Прямая пирамидка
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }    
/*
    // Обратная пирамидка
    for(int i = 1, n_1 = n; i <= n; ++i, --n_1) {
        for(int j = 1;j <= n_1 ; ++j) {
            printf("*");
        }
        printf("\n");
    }
*/


    return 0;
}