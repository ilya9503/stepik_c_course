#include <stdio.h>

typedef struct {
    double re; // действительная часть 
    double im; // мнимая часть
} COMPLEX;

// здесь объявляйте функцию
COMPLEX complex_sum(COMPLEX a, COMPLEX b){
    return (COMPLEX) {a.re + b.re, a.im + b.im};
}

int main(void)
{
    // здесь продолжайте функцию main
    COMPLEX cmp_1, cmp_2;
    scanf("%lf, %lf, %lf, %lf", &cmp_1.re, &cmp_1.im, &cmp_2.re, &cmp_2.im);
    COMPLEX res = complex_sum(cmp_1, cmp_2);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать)
    return 0;
}