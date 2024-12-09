/*
    Продолжите программу. Объявите функцию с именем is_win,
    которой передается двумерный массив типа char размером SIZE x SIZE элементов.
    Функция is_win должна проверять и возвращать статус переданного игрового поля
    игры "Крестики-нолики" в виде целого числа:

    0 - игра не окончена;
    1 - выиграли "крестики";
    2 - выиграли "нолики";
    3 - ничья.

    Каждый элемент переданного двумерного массива хранит либо символ 'x', либо
    символ 'o', либо целое число 0, если клетка свободна.

    В функции main вызовите функцию is_win для массива pole.
    Выведите в консоль вычисленный статус игрового поля в виде целого числа.

*/
#include <stdio.h>

#define SIZE    3

int is_win(const char ar[SIZE][SIZE]);

int main(void)
{
    char pole[SIZE][SIZE] = {0};
    char* ptr_p = &pole[0][0];
    int count = 0;
    while(count < SIZE * SIZE && scanf("%d", ptr_p) == 1) {
        *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o': *ptr_p;
        ptr_p++;
        count++;
    }

    // здесь продолжайте программу
    printf("%d", is_win(pole));


    return 0;
}

// Выиграли х или о
int is_win_ch(const char ar[SIZE][SIZE], char ch)
{
    for(int i = 0; i < SIZE; ++i) {
        int j = 0;
        if(ar[i][j] == ch && ar[i][j+1] == ch && ar[i][j+2] == ch)
            return 1;   // горизонтали
        if(ar[j][i] == ch && ar[j+1][i] == ch && ar[j+2][i] == ch)
            return 1;   // вертикали
    }

    if(ar[0][0] == ch && ar[1][1] == ch && ar[2][2] == ch)            
        return 1;   // диагональ 1
    else if(ar[2][0] == ch && ar[1][1] == ch && ar[0][2] == ch)            
        return 1;   // диагональ 2
    else
        return 0;   // ch не выиграл
}

// Есть нули - true, нет нулей - false
int check_0(const char ar[SIZE][SIZE])
{
    int zero_flag = 0;
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            zero_flag = (ar[i][j]) == 0 ? 1 : zero_flag;
    return zero_flag;
}

// Статус игры крестики-нолики
int is_win(const char ar[SIZE][SIZE])
{
    if(is_win_ch(ar, 'x'))
        return 1;
    else if(is_win_ch(ar, 'o'))
        return 2;
    else if( ! check_0(ar))
        return 3;
    else
        return 0;
}