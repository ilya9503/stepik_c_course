#include <stdio.h>
#include <string.h>
#include <stdarg.h>     // var function

typedef struct {
    char fname[100];    // Фамилия
    char old;           // Возраст
    char stag;          // Стаж
    int salary;         // Зарплата
    double efs;         // Эффективность труда сотрудника
} PERSON;

void fill_data(PERSON* p, char* format, ...)
{
    va_list arg;                // указатель на параметр
    va_start(arg, format);       // получение адреса первого вариадического параметра
    char cur_ch;

    while(strchr(format, '#') != NULL) {
        format++;
        cur_ch = format[0];
        switch (cur_ch) {
            case 'f':
                strcpy(p->fname, va_arg(arg, char*));
                break;
            case 'o':
                p->old = va_arg(arg, int);
                break;
            case 'g':
                p->stag = va_arg(arg, int);
                break;
            case 's':
                p->salary = va_arg(arg, int);
                break;
            case 'e':
                p->efs = va_arg(arg, double);
                break;
            default:
                break;
        }
    }
    va_end(arg);
    return;
}

int main(void)
{
    PERSON pers;
    char format[20] = "#o #e #s #f";    // определяет какие данные из структуры записать в pers
    fill_data(&pers, format, 35, 0.75, 3000, "Putin");
    printf("o = %d, e = %.2f, s = %d, f = %s", pers.old, pers.efs, pers.salary, pers.fname);

    return 0;
}