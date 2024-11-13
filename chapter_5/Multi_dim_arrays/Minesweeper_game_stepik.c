#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    10
#define MINES   12

#define VERIFICATION \
pg[rows][cols] == '*' ||\
pg[rows][cols - 1] == '*' ||\
pg[rows][cols + 1] == '*' ||\
pg[rows - 1][cols] == '*' ||\
pg[rows - 1][cols - 1] == '*' ||\
pg[rows - 1][cols + 1] == '*' ||\
pg[rows + 1][cols] == '*' ||\
pg[rows + 1][cols - 1] == '*' ||\
pg[rows + 1][cols + 1] == '*'


int main(void)
{
    char pg[SIZE][SIZE] = {0};
    int rows, cols;
    int mine = 0;

    srand (time(NULL));
    while (mine < 12){
        rows = rand() % 10;
        cols = rand() % 10;
        if (VERIFICATION){
            continue;
        }
        pg[rows][cols] = '*';
        mine++;
    }

for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
        printf("%c ", pg[i][j]);
    }
    printf("\n");
}

printf("Количество мин на поле 10х10: %d\n", mine);

    return 0;
}