#include <stdio.h>
#include <stdlib.h>
#include <time.h>       /* time */

#define SIZE    10
#define MINES   12

int main(void)
{
    char pg[SIZE][SIZE] = {0};

    // здесь продолжайте программу
    int mine_i = 0;
    int mine_j = 0;
    int mine_count = 0;
    // initialize random seed: 
    srand (time(NULL));


while (mine_count <= MINES) {
   
    mine_i = rand() % 10;       // Генерим число [0-9] по строкам
    mine_j = rand() % 10;       // Генерим число [0-9] по столбцам

    pg[mine_i][mine_j] = '*';
    ++mine_count;   // +1 мина

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (pg[i][j] == '*') {
                // Если в окружении есть другие мины, обнуляем текущую мину
                if ((pg[i][j-1] == '*') || (pg[i][j+1] == '*') || (pg[i-1][j] == '*') || (pg[i-1][j-1] == '*') || (pg[i-1][j+1] == '*') || (pg[i+1][j] == '*') || (pg[i+1][j-1] == '*') || (pg[i+1][j+1] == '*')) {
                    pg[i][j] = 0;
                    --mine_count;   // -1 мина
                }
            }
        }
    }
}

    // Счетчик мин
    int mine_count_1 = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (pg[i][j] == '*')
                ++mine_count_1;
        }
    }   


for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
        printf("%c ", pg[i][j]);
    }
    printf("\n");
}

printf("Количество мин на поле 10х10: %d\n", mine_count);
printf("Количество мин на поле 10х10 реальное: %d\n", mine_count_1);


//    __assert_verify_pg(pg); // для тестирования (не убирать и должна идти непосредственно перед return 0)
    return 0;
}