#include <stdio.h>
/*
int num_cmp_2(int a, int b)
{
    return a > b ? a : b;
}

int num_cmp_3(int a, int b, int c)
{
    return num_cmp_2(num_cmp_2(a, b), c);
}

int num_cmp_4(int a, int b, int c, int d)
{
    return num_cmp_2(num_cmp_3(a, b, c), d);
}
*/
int sum_big2(int a, int b, int c, int d)
{
    int arr[] = {a, b, c, d};
    for(int i = 0; i < 3; ++i) {
        int pos = i;
        // 1. Ищем максимальный индекс
        for(int j = i; j < 4; ++j)
            if(arr[pos] > arr[j])
                pos = j;
        // 2. Если индекс отличается, от текущего, меняем их местами
        if (pos != i) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
    return arr[2] + arr[3];
}

int main(void)
{
    // здесь продолжайте функцию main
    int a, b, c, d;
    if(scanf("%d %d %d %d", &a, &b, &c, &d) != 4) {
        printf("Incorrect input!");
        return 0;
    }

    printf("%d", sum_big2(a, b, c, d));

    return 0;
}