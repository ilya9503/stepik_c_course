#include <stdio.h>

/*
    Рекомендации к написанию программ:
    1. Оператор SWITCH лучше выносить в отдельную функцию и прерывать с помощью RETURN
    2. После каждой метки CASE прописывать функцию вместо набора операторов
    3. НИКОГДА не использовать вложенные операторы SWITCH
*/

int main (void)
{
    char item;

    printf( "1. Learning C language\n"
            "2. Learning Python language\n"
            "3. Learning Java language\n"
            "4. Learning C++ language\n"
            "5. Exit\n");

    if (scanf("%c", &item) != 1) {
        printf("Error input");
        return 0;
    }

    /*
        Значение переменной item поочередно сравнивается с меткой case
        Если item == case, выполняется метка case И ВСЕ последующие метки
        Ключевое слово BREAK прерывает работу оператора SWITCH и передает управление следующему оператору
        Ключевое слово RETURN завершает работу текущей функции (в которой находится SWITCH)
     
    switch(item) {
        case 1:
            printf("Learning C language\n");
            break;  // завершает SWITCH, передает управление след ф-ции
        case 2:
            printf("Learning Python language\n");
            return 0;   // завершает работу текущей функции
        case 3:
            printf("Learning Java language\n");
        case 4:
            printf("Learning C++ language\n");
        case 5:
            printf("Exit\n");
    }
*/
    switch(item) {
        case 'a':
        case 'A':
            printf("Symbol A\n");
            break;
        case 'b':
        case 'B':
            printf("Symbol B\n");
            break;
        case 'c':
        case 'C':
            printf("Symbol C\n");
            break;
        default:
            printf("Incorrect symbol\n");
            // Нужно писать break, если находится не в конце 
    }

    return 0;
}