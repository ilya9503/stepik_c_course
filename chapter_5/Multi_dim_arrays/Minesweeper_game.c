/*
    Игра "Сапер":
    Напишите программу в которой на двумерное игровое поле размерностью 10 x 10 случайным образом
    размещаются 12 "мин" так, чтобы они не соприкасались друг с другом
    (вокруг клетки с миной не должно быть других мин).

    Игровое поле должно быть представлено двумерным массивом с именем pg, типом char и размерностью 10 х 10.

    Пустые клетки (без мин) должны принимать значение 0, а клетки с минами помечаются символом '*'.

    P. S. В консоль ничего выводить не нужно.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE    10
#define MINES   12

int main(void)
{
    char pg[SIZE][SIZE] = {0};

    // здесь продолжайте программу

//    __assert_verify_pg(pg); // для тестирования (не убирать и должна идти непосредственно перед return 0)
    return 0;
}