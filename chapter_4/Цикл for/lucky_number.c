/*
    Напишите программу, которая читает из входного потока шестизначное натуральное
    число n. Определить, является ли оно счастливым.
    (Счастливым называют такое шестизначное число, в котором сумма его первых 
    трех цифр равна сумме его последних трех цифр.).
    Вывести в консоль "yes", если счастливое и "no" - в противном случае.
*/
#include <stdio.h>

int main(void)
{
    int n;
    int m = 0;
    int old_n;
    int right = 0, left = 0;

    scanf("%d", &n);

    // Правая часть
    for (int i = 1 ;i <= 3 ;++i ) {
        int temp = n % 10; 
        old_n = n;     
        n = n / 10;    
        m += temp;
        printf("Inside of 1st cycle: m = %d\n", m);
    }
    printf("After 1st cycle m = %d, n = %d\n", m, n );
    right = m;
    m = 0;
    
    // Левая часть
    for ( ;n ;) {
        int temp = n % 10;     
        n = n / 10;    
        m += temp;
        printf("Inside of 2nd cycle: m = %d\n", m);
    }
    printf("After 2nd cycle : m = %d, n = %d\n", m, n);
    left = m;
    m = 0;

    right == left ? printf("yes") : printf("no");


    
    return 0;
}