/*

*/

#include <stdio.h>

#define SIZE    4

void transpose(short ar[SIZE][SIZE]);
void show_ar2D(const short (*ar)[SIZE], int rows);


int main(void)
{
    short matrix[SIZE][SIZE] = {0};

    short* ptr = &matrix[0][0];
    int count = 0;
    while(count < SIZE * SIZE && scanf("%hd", ptr) == 1) {
        ptr++;
        count++;
    }

    // здесь продолжайте программу
    transpose(matrix);
    show_ar2D(matrix, SIZE);

    return 0;
}

// Замена строк на столбцы массива
void transpose(short ar[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; ++i) {
        for(int j = i; j < SIZE; ++j) {
                short temp = 0;
                temp = ar[i][j];
                ar[i][j] = ar[j][i];
                ar[j][i] = temp;
        }
    }
    return;
}

// Выводим двумерного массива в консоль.
void show_ar2D(const short (*ar)[SIZE], int rows)
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            printf("%d", ar[i][j]);
            if(j < SIZE-1)
                printf(" ");
        }
        if(i < SIZE-1)
            printf("\n");
    }
}