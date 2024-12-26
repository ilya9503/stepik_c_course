#include <stdio.h>

int find_dividers(int ar[], int num, int len)
{
    int count = 0;
    // перебираем все числа от 1 до n
    for (int i = 1; i <= num; ++i) {
        if(num % i == 0 && count < len) {
            ar[count] = i;
            ++count;
        }
    }
    return count;
}

void printf_array(int ar[], int count)
{
    for (int i = 0; i < count; ++i)
        printf("%d ", ar[i]);
}

int main(void)
{
    int x = 0;
    int dividers[20] = {0};
    int quantity = 0;
    int len = sizeof(dividers) / sizeof(*dividers);

    if(scanf("%d", &x) != 1) {
        printf("Input error!");
        return 0;
    }

    quantity = find_dividers(dividers, x, len);
    printf_array(dividers, quantity);

    return 0;
}