#include <stdio.h>
#include <string.h>

enum {name_length=50, b_length=20};
 
struct tag_fio {
    char name[name_length]; /* имя */
    char last[name_length]; /* фамилия */
};

struct tag_person {
    struct tag_fio fio;     /* ФИО, вложенная структура*/
    char sex;               /* пол: м или ж */
    unsigned short old;     /* возраст */
    char b_date[b_length];   /* дата рождения */
};

int main(void) 
{
    struct tag_person person = {    // объект структуры типа tag_person person
        {"Sergey", "Balakirev"},    // инициализация вложенной структуры
        'M',
        98,
        "32.07.1925"
    };

    struct tag_person p;            // объект структуры типа tag_person p

    p = person;     // копируем все поля структуры person в структуру p

    person.old = 17;
    strcpy(person.b_date, "31.07.2006");

    printf("sex: %c, b_date: %s\n", person.sex, person.b_date);
    printf("name: %s, last: %s\n", person.fio.name, person.fio.last);   // обращение к вложенной структуре
 
    return 0;
}