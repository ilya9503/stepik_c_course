#include <stdio.h>

int main(void)
{

/*
    // Задача 1
    int a;
    short b;
    float c;
    double d;

    int count = scanf("%d %hd %f %lf", &a, &b, &c, &d);
    printf("%d %d %.2f %.2f\n", a, b, c, d);
    printf("count = %d\n", count);

    // Задача 2
    int num1, num2;

    int count = scanf("%d; %d", &num1, &num2);
    printf("%d %d", num1, num2);

   // Задача 3
    int iv1, iv2;
    double dv1, dv2;

    int count = scanf("%d, %d, %*lf, %lf", &iv1, &iv2, &dv2);
    printf("%d %d %.2f", iv1, iv2, dv2);


    int g = sizeof(short);          //2
    int g1 = sizeof(int);           //4
    int g2 = sizeof(long);          //4
    int g3 = sizeof(long long);     //8

    int val1;
    float val2, val3;

    int count = scanf("%d %f %f", &val1, &val2, &val3);

    printf("%d %.2f %.2f", val1, val2, val3);


    double v1,v2,v3,v4,v5,v6,v7,v8,v9,v10;
    
    int count = scanf("%lf; %lf; %lf; %lf; %lf; %lf; %lf; %lf; %lf; %lf", &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9, &v10);
    printf("%.1f %.1f %.1f %.1f %.1f count = %d", v6, v7, v8, v9, v10, count);
*/

    int a, b, count, temp;

    count = scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    swap(&a, &b);

    printf("%d %d", a, b);



    return 0;
}

// Функция подмены зн-ий 2 переменных
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }