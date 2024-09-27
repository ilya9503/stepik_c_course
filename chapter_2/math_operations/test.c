#include <stdio.h>
#include <tgmath.h>

void a_prog();   // прототип функции
void g_prog();
void sqrt_my();
void circle_r();
void trapeze_square();

int main(void)
{
/*
    double b;
    b = 6.0 * (1.0 / 3.0) * (1.0 / 3.0) - 15.0 * (1.0 / 3.0);
    printf("%.2f", b);

    int h, w;
    scanf("%d %d", &h, &w);
    double res = (double)h / (double)w;
    printf("%.2f", res);

    int count = 0;
    scanf("%d", &count);

    // здесь продолжайте программу
    // count = ++count;
    count++;
    printf("%d", count);

    int a1; // первый член прогрессии
    int a50; // 50-й член прогрессии
    scanf("%d, %d", &a1, &a50);
    a_prog(a1, a50);
    g_prog(a1,a50);
*/
    int a, b, h;
    scanf("%d, %d, %d", &a, &b, &h);
    trapeze_square(a, b, h);



    return 0;
}

// Арифметическая прогрессия
void a_prog(int a, int b)
{
    double temp = ((double)a + (double)b) / 2.0 * 50.0;
    int temp1 = (int) temp;
    printf("%d", temp1);
}

//Геометрическая прогрессия
void g_prog(int q, int b1)
{
    double n = 4.0;
    double s = ((pow((double)q, n) - 1.0) * (double)b1) / ((double)q - 1.0);
    printf("%d", (int)s);
}

void sqrt_my(int a)
{
    double r = (sqrt(3.0) * (double)a) / 6.0;
    printf("%.3f", r);
}

void circle_r(double r)
{
    double R = 2.0 * 3.1415 * r;
    printf("%.3f", R);
}

void trapeze_square(int a, int b, int h)
{
    double s = (double)((a + b) * h) / 2.0;
    printf("%.1f", s);
}
