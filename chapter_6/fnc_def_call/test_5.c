#include <stdio.h>

int is_triangle(int a, int b, int c) {
    if(a < (b + c) && b < (a + c) && c < (a + b))
        return 1;
    else
        return 0;
}

int main(void)
{
    // здесь продолжайте функцию main
    int a, b, c, res;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Incorrect input!");
        return 0;
    }

    res = is_triangle(a, b, c);
    printf("%d", res);

    return 0;
}