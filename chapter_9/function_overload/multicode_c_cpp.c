/*
    Код, который будет компилироваться на С и на С++
    Благодаря директивам условной компиляции
*/
#ifdef __cplusplus
#   include <iostream>
extern "C" {
#else
#   include <stdio.h>
#endif

double mean_2(int a, int b)
{
    return (double)(a + b) / 2.0;
}

#ifdef __cplusplus
}
#endif

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.1f", mean_2(a, b));

    return 0;
}










