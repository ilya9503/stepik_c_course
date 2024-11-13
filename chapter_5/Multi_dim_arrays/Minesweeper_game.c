/*
    Игра "Сапер":
    Напишите программу в которой на двумерное игровое поле размерностью 10 x 10 случайным образом
    размещаются 12 "мин" так, чтобы они не соприкасались друг с другом
    (вокруг клетки с миной не должно быть других мин).

    Игровое поле должно быть представлено двумерным массивом с именем pg, типом char и размерностью 10 х 10.

    Пустые клетки (без мин) должны принимать значение 0, а клетки с минами помечаются символом '*'.

    P. S. В консоль ничего выводить не нужно.

    https://minesweeper.online/
*/

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define SIZE    10
#define MINES   12

int main(void)
{
    char pg[SIZE][SIZE] = {0};
    int mine_i[MINES];      // Массив с индексами строк для мин
    int mine_j[MINES];      // Массив с индексами столбцов для мин
    int m = 0;              // Счетчик мин
    int mine_i_cur;
    int mine_i_old;    

    // здесь продолжайте программу
  
    /* initialize random seed: */
    srand (time(NULL));
    /*
    for(int i = 0; i < MINES; ++i) {
        while(1) {
            mine_i_cur = rand() % 10;       // Генерим число [0-9] по строкам
            mine_i[i] = mine_i_cur;
            mine_i_old = mine_i_cur;
            mine_i_cur = rand() % 10;       // Генерим число [0-9] по строкам

            if( (mine_i_cur != mine_i_old) &&
                ((mine_i_cur + 1) != mine_i_old) &&
                ((mine_i_cur - 1) != mine_i_old))
                break;
        }
    }
        



























    /*
        v1 = rand() % 100;         // v1 in the range 0 to 99
        v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
        v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 

    */
   /*
    mine_i = rand() % 10;       // Генерим число [0-9] по строкам
    mine_j = rand() % 10;       // Генерим число [0-9] по столбцам

    pg[mine_i][mine_j] = '*';   // Закладываем мину
    m += 1;                     // Счетчик мин

    do
    {
        mine_i = rand() % 10;       // Генерим число [0-9] по строкам
        mine_i_old = mine_i;
        mine_i = rand() % 10;
        if () {
            
        }
        
    } while (/* condition */);
    
/*
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; i < SIZE; ++j) {
            // Если в ячейке 0, генерим следующую мину
            if(pg[i][j] == 0) {
                while (/* condition */) {
                    mine_i = rand() % 10;       // Генерим число [0-9] по строкам
                    mine_j = rand() % 10;       // Генерим число [0-9] по столбцам
                }
            }
            if (/* condition */) {
                /* code */
            }
            
        } 
    }

    pg[mine_i][mine_j] = '*';   // Закладываем мину
*/       
//    __assert_verify_pg(pg); // для тестирования (не убирать и должна идти непосредственно перед return 0)
    return 0;
}