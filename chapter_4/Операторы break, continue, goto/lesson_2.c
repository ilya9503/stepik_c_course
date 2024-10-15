/*
    Выведем все числа кратные только 3 и 5
*/
#include <stdio.h>

int main(void)
{
    for(int i = 1; i <= 100; ++i) {
        if(i % 3 != 0 || i % 5 != 0)
            continue;
        printf("%d ", i);
    }



    return 0;
}