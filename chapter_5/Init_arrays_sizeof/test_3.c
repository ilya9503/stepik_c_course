#include <stdio.h>

short marks[] = {1, 2, 3, 4, 5};

int main(void)
{
    // здесь продолжайте функцию main
    double sum = 0.0;
    int n = sizeof marks / sizeof *marks;
    for(int i = 0; i <= n - 1 ; ++i) {
        sum += marks[i];
    }
    printf("%.2f ", sum / n);

    return 0;
}