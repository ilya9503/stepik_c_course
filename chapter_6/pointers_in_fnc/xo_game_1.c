/*
    короткое решение
*/
#include <stdio.h>

#define SIZE    3

int is_win(char*);
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
    
    printf("%d", is_win(&pole[0][0]));

    // здесь продолжайте программу

    return 0;
}

int is_win(char *pole){
    int isEmpty = 0;
    for(int i = 0; i < SIZE; ++i){
        int sumH = 0;
        int sumV = 0;
        int sumD1 = 0;
        int sumD2 = 0;
        
        for(int j = 0; j < SIZE; ++j){
           
            sumH += *(pole + i * SIZE + j);
            sumV += *(pole + j * SIZE + i);
            sumD1 += *(pole + j * SIZE + j);
            sumD2 += *(pole + j * SIZE + SIZE - j - 1);
            if(*(pole + i * SIZE + j) == 0) isEmpty = 1;
   
        }

        if(sumH == 'x' * 3 || sumV == 'x' * 3 || sumD1 == 'x' * 3 || sumD2 == 'x' * 3){
            return 1;
        }
        if(sumH == 'o' * 3 || sumV == 'o' * 3 || sumD1 == 'o' * 3 || sumD2 == 'o' * 3){
            return 2;
        }
    }
    if(isEmpty != 0) return 0;

    return 3;
}