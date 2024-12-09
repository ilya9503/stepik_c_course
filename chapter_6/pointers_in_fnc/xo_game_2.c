/*
    универсальное решение
*/
#include <stdio.h>

#define SIZE    3

int check_row(char pole[SIZE][SIZE], int row) {
    int win_x = 1;
    int win_o = 1;
    
    for (int i = 0; i < SIZE; ++i) {
        if (pole[row][i] == 0)
            return 0;

        win_x *= pole[row][i] == 'x';
        win_o *= pole[row][i] == 'o';
    }

    return win_x ? 1 : win_o ? 2 : 3;
}

int check_col(char pole[SIZE][SIZE], int col) {
    int win_x = 1;
    int win_o = 1;

    for (int i = 0; i < SIZE; ++i) {
        win_x *= pole[i][col] == 'x';
        win_o *= pole[i][col] == 'o';
    }

    return win_x ? 1 : win_o ? 2 : 3;
}

int check_diag(char pole[SIZE][SIZE]) {
    int win_x1 = 1;
    int win_o1 = 1;
    int win_x2 = 1;
    int win_o2 = 1;

    for (int i = 0; i < SIZE; ++i) {
        win_x1 *= pole[i][i] == 'x';
        win_o1 *= pole[i][i] == 'o';
        win_x2 *= pole[i][SIZE - 1 - i] == 'x';
        win_o2 *= pole[i][SIZE - 1 - i] == 'o';
    }

    return win_x1 || win_x2 ? 1 : win_o1 || win_o2 ? 2 : 3;
}

int is_win(char pole[SIZE][SIZE]) {
    int flag_0 = 1;
    for (int i = 0; i < SIZE; ++i) {
        int row_res = check_row(pole, i);
            if (row_res == 1 || row_res == 2)
                return row_res;
            flag_0 *= row_res > 0;

        int col_res = check_col(pole, i);
            if (col_res != 3)
                return col_res;
    }

    int diag_res = check_diag(pole);
    return diag_res == 1 || diag_res == 2 ? diag_res : diag_res * flag_0;
}

int main(void) {
    char pole[SIZE][SIZE] = { 0 };
    char* ptr_p = &pole[0][0];
    int count = 0;
    while (count < SIZE * SIZE && scanf("%d", ptr_p) == 1) {
        *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o' : *ptr_p;
        ptr_p++;
        count++;
    }

    int res = is_win(pole);
    printf("%d\n", res);

    return 0;
}