#include <stdio.h>

int main(void)
{
    int num = 725, i = 2;
    //scanf("%d", &num);

    while(num != 1)
    {
        if(num % i == 0)
        {
            printf("%d ", i);
            num /= i;
            continue;
        }
        i++;
    }

    return 0;
}