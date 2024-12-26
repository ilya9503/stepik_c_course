#include <stdio.h>

int get_multipliers(int n, int ar[], int len);
int find_dividers(int ar[], int num, int len);
int is_prime(int n);
void printf_array(int ar[], int count);

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

    quantity = get_multipliers(x, dividers, len);
    printf_array(dividers, quantity);

    return 0;
}

int get_multipliers(int n, int ar[], int len)
{
    int count = 2;  // число, на которое делим
    int i = 0;
    while (n != 1) {
        // если n не делится нацело на count, инкрементируем
        if(n % count != 0)
            ++count;
        else {
            n /= count;
            ar[i] = count;
            ++i;
        }
    }
    return i;
}

// Функция находит все делители числа num (натуральные числа, которые нацело делят число n, начиная с 1)
int find_dividers(int ar[], int num, int len)
{
    int count = 0;
    for (int i = 1; i <= num; ++i) {
        if(num % i == 0 && count < len) {
            ar[count] = i;
            ++count;
        }
    }
    return count;
}

// Функция проверки, является ли натуральное число простым
int is_prime(int n)
{
    // Число n является простым, если оно отлично от 1 и делится без остатка только на 1 и на n 
    if(n <= 1)
        return 0;
    for(int i = 1; i <= n; ++i)
        if(n % i == 0)
            if(i > 1 && i < n)
                return 0;
    return 1;
}

// Функция вывода массива на экран
void printf_array(int ar[], int count)
{
    for (int i = 0; i < count; ++i)
        printf("%d ", ar[i]);
}