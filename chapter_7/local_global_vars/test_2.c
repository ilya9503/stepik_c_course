#include <stdio.h>

int range_check(int x)
{
    return x >= 1 && x <= 5 ? 1 : 0;
}

double mean_ar(const int *ar, size_t len_ar, int (*range)(int))
{
    // здесь продолжайте функцию
    int i = 0, count = 0;
    double res = 0;
    while (i < len_ar) {
        if(range(ar[i])) {
            res += ar[i];
            ++count;
        }
        ++i;
    }
    return res / count;
}

int main(void)
{
    int marks[20] = {0};
    int x;
    int count = 0;
    double res = 0.0;
    while(scanf("%d", &x) == 1 && count < 20) {
        // здесь продолжайте программу
        marks[count] = x;
        ++count;
    }

    res = mean_ar(marks, sizeof(marks) / sizeof(*marks), range_check);
    printf("%.1f", res);

    return 0;
}