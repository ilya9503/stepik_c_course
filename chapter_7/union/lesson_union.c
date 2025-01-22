/*
    Объединение - составной тип данных, схожий со структурой

    union [имя объединения] {
        [поля]
    }
    Все поля СТРУКТУРЫ в памяти располагаются по порядку друг за другом.
    В ОБЪЕДИНЕНИИ все переменные хранятся с одного и того же начального адреса.

    Структура хранит в памяти последовательно все переменные = сумма байт всех полей (переменных)
    В объединении область памяти переменных накладываются друг на друга = кол-во байт наибольшего поля

    Объединение хранит последнее записанное в него значение

    Предназначение объединений:
    Создание универсальной переменной, которая могла бы хранить или байтовые значения, или целочисленные, или вещественные.
        То есть, какое-то одно значение в один момент времени.
*/

#include <stdio.h>

typedef enum {  // перечисление констант для понимания какая из переменных была заполнена последней
    union_var_none, union_var_ch, union_var_i, union_var_d
} TYPE_VAR;

union tag_var { // double наибольшая, поэтому 8 байт
    char var_ch;
    int var_i;
    double var_d;
};

struct tag_var_st { // 1 + 4 + 8 = 13 байт
    char var_ch;
    int var_i;
    double var_d;
};

typedef struct {
    union tag_var var;
    TYPE_VAR type;
} VAR;

void show_var(VAR v)
{
    // Выбираем что вывести в зависимости от последнего записанного зн-я
    switch(v.type) {
    case union_var_ch:
        printf("var_ch = %c\n", v.var.var_ch);
        break;
    case union_var_i:
        printf("var_i = %d\n", v.var.var_i);
        break;
    case union_var_d:
        printf("var_d = %.2f\n", v.var.var_d);
        break;
    case union_var_none:
        puts("Undefined type var");
        break;
    }
}


int main(void) 
{
    VAR var;
    union tag_var* t_v;
    var.var.var_ch = 'C';
    var.type = union_var_ch;
    //var.var.var_i = 45;

    show_var(var);

    return 0;
}