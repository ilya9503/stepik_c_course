#include <stdio.h>

int main(void)
{
    int num, summ = 0;

    do
    {
        scanf("%d", &num);
        if(num >= 0)
            summ += num;

    } while (num != 13);

    printf("%d", summ);
    
    return 0;
}