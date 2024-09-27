#include <stdio.h>

int main(void)
{
    // Задание 1
    char ch = 'u';
    short sh = -55;
    int var_i = 1024;
    double var_d = 3.1415;

//    printf("%c %d %d %f\n", ch, sh, var_i, var_d);

    // Задание 2
/*
    char byte = 65;
    unsigned short height = 1055;
    int distance = 1000000;
    float pi = 3.1415f;

    printf("%c\n", byte);
    printf("%u\n", height);
    printf("%d\n", distance);
    printf("%.4f\n", pi);
*/
    // Задание 3
    unsigned height = 12345012;
    long long dist = 1234567890LL;
    long double weight = 45.7845;

 //   printf("%u %lld %.4Lf\n", height, dist, weight);

    // Задание 4
    int a1 = -123, a2 = 6, a3 = 1024;
    double d = 546e-3;
/*
    printf("[%5d]\n", a1);
    printf("[%5d]\n", a2);
    printf("[%5d]\n", a3);
    

    printf("%.3f\n", d);
    printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
*/
    // Задание 5
    unsigned char h = 17, m = 16, s = 15;
    int q;

//    printf("%02u:%02u:%02u", h, m, s);
    q = printf("0x%02x:0x%02x:0x%02x\n", h, m, s);
    printf("Число выведенных символов : %d", q);


    return 0;
}