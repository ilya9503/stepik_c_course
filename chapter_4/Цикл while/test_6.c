#include <stdio.h>

int main(void)
{
    int a, b, min, max;
    /*
        Ограничения натуральных чисел
    */
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Error input");
        return 0;
    }

    printf("%d %d\n", a, b);

   if (a <= 0 || b <= 0) {
        printf("Not a natural number");
        return 0;
   }

   /*
        Выбираем минимальное
   */
    if (a < b) {
        min = a;
        max = b;
    }
    else {
        min = b;
        max = a;
    }

    while (min > 0) {
        max = max % min;
        // swap
        int temp = max;
        max = min;
        min = temp;
    }

    printf("%d", max + min);
    
    return 0;
}