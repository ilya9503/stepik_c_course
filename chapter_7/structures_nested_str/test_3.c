#include <stdio.h>
#include <string.h>

// здесь объявляйте структуры
enum {num = 50};

typedef struct tag_fio {
    char firstname[num];
    char otch[num];
    char lastname[num]; 
} TAG_FIO;

typedef struct tag_student {
    TAG_FIO fio;
    short old;
    short height;
    short weight;
} TAG_STUDENT;

void getline(char* buffer, size_t max_len)
{
    fgets(buffer, max_len-1, stdin);
    char* ptr_n = strrchr(buffer, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
}

int main(void)
{
    char fname[50], otch[50], lname[50]; // имя, отчество, фамилия
    short old, height, weight; // возраст, высота, вес

    getline(fname, sizeof(fname));
    getline(otch, sizeof(otch));
    getline(lname, sizeof(lname));

    scanf("%hd, %hd, %hd", &old, &height, &weight);

    // здесь продолжайте программу
    TAG_STUDENT st = {.old = old, .height = height, .weight = weight};  // инициализируем структуру
    strcpy(st.fio.firstname, fname);
    strcpy(st.fio.otch, otch);
    strcpy(st.fio.lastname, lname);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}