#include <stdio.h>

#define N   5

// Функция отображения поля
void show_pole(const char (*p)[N])
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            printf("%c ", (p[i][j] == 0) ? '#' : '0');
        putchar('\n');
    }
}

void open_zeros(const char (*p)[N], char (*pp)[N], int i, int j)
{
    /*
        1. ppole заполняется 1, там где pole были 0.
        2. Выводим на экран # вместо 0 и 0 вместо 1.
    */
    if(p[i][j] != 0 || pp[i][j] == 1)
        return;
    pp[i][j] = 1;
    if(i-1 >= 0 && p[i-1][j] == 0) open_zeros(p, pp, i-1, j);
    if(i+1 < N && p[i+1][j] == 0) open_zeros(p, pp, i+1, j);
    if(j-1 >= 0 && p[i][j-1] == 0) open_zeros(p, pp, i, j-1);
    if(j+1 < N && p[i][j+1] == 0) open_zeros(p, pp, i, j+1);
}

int main(void)
{
    char pole[N][N] = {     // Игровое поле 5х5 клеток. То, что реально находится на поле
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
    };

    char ppole[N][N] = {0}; // Игровое поле 5х5 клеток, закрытое от игрока

    show_pole(ppole);
    open_zeros(pole, ppole, 2, 2);
    puts("----------------------");
    show_pole(ppole);

    return 0;
}