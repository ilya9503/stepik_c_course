#include <stdio.h>

#define SIZE    3

// Выводим двумерного массива в консоль.
void show_ar2D(const char (*ar)[SIZE], int rows)
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if(j != SIZE-1)
                printf("%c ", ar[i][j]);
            else
                printf("%c", ar[i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    char pole[SIZE][SIZE] = {0};
    char* ptr_p = &pole[0][0];
    int count = 0;
    int val = 0;

    while(count < SIZE * SIZE && scanf("%d", &val) == 1) {
        
        *ptr_p = (val == 1) ? 'x' : (val == 2) ? 'o': (val == 0) ? '#' : val;
        ptr_p++;
        count++;
    }

    // здесь продолжайте программу
    show_ar2D(pole, SIZE);

    return 0;
}