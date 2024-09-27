#include <stdio.h>

int show_menu(void)
{
    char menu_item;

    printf("a) learning english\n\
b) learning C/C++\n\
c) learning mathematic\n\
d) learning Python\n");

    // здесь прописывайте функцию scanf() и оператор switch
    if(scanf("%c", &menu_item) != 1) {
        printf("Input error.");
        return 0;
    }
        switch (menu_item)
    {
    case 'a':
    case 'A':
        return 1;
    case 'b':
    case 'B':
        return 2;
    case 'c':
    case 'C':
        return 3;
    case 'd':
    case 'D':
        return 4;
    }
    return -1;
}

int main(void)
{
    int item = show_menu();

    // здесь выводите значение переменной item
    printf("%d", item);

    return 0;
}