#include <stdio.h>

unsigned int counter()
{
    // cnt создается 1 раз при запуске программы, как глобальная
    static unsigned int cnt = 10;
    return ++cnt;
}

int main(void)
{
    unsigned int times;
    times = counter();
    printf("times = %u\n", times);
    printf("counter(): %u\n", counter());
    printf("counter(): %u\n", counter());
    printf("counter(): %u\n", counter());

    return 0;
}