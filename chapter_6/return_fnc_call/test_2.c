#include <stdio.h>

int get_sum2(int a, int b)
{
    return a + b;
}

int main(void)
{
    // здесь продолжайте функцию main
    int a, b, c;
    int res;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Incorrect input!");
        return 0;
    }

    res = get_sum2(get_sum2(a, b), c);
    printf("%d", res);

    return 0;
}