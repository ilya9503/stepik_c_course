#include <stdio.h>
#include <stdbool.h>    // добавляет замену _Bool на bool. Добавляет ключевые слова true/false

int main(void)
{
    int a;
//    scanf("%d", &a);
    int b = a % 5 == 0;

//    printf("%d", 100 * b);

    double d;
    scanf("%lf", &d);
    _Bool d1 = (int)d % 5;

    printf("%d", ! d1);  
    return 0;
}