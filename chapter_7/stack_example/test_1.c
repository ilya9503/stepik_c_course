/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN     1024

/*  Структура объекта стека */
typedef struct tag_obj {    
    char url[MAX_LEN];       //  Данные 
    struct tag_obj* next;   //  Указатель на следующий объект стека. Указатель на текущую структуру
} OBJ;

/*  
    Функция добавления нового объекта в стек
        top - Указатель на вершину стека
        data - Данные, которые нужно сохранить в стеке
*/
OBJ* push(OBJ* top, const char* url)
{
    OBJ* ptr = malloc(sizeof(OBJ));     // создаем новый объект для структуры, выделяем память в куче
    strcpy(ptr->url, url);              // заполняем поля структуры (разыменывание)
    ptr->next = top;
    return ptr;                         // возвращаем указатель на новый созданный объект
}

/*
    Функция извлечения самого врехнего объекта из стека и удаление его
*/
OBJ* pop(OBJ* top)
{
    if(top == NULL)
        return top;

    OBJ* ptr_next = top->next;
    free(top);                  // освобождаем ранее выделенную память, тем самым удаляем объект

    return ptr_next;            // возвращаем адрес следующего объекта
}

int main(void)
{
    OBJ* top = NULL;        /*  Указатель на самый верхний объект стека. Если NULL - стек пуст */
    top = push(top, "https://proproprogs.ru/c_base/c_etapy-translyacii-programmy-v-mashinnyy-kod-standarty");     
    top = push(top, "https://proproprogs.ru/c_base/c_struktura-i-ponimanie-raboty-programmy-hello-world");
    top = push(top, "https://proproprogs.ru/c_base/c_dvoichnaya-shestnadcaterichnaya-i-vosmerichnaya-sistemy-schisleniya");
    top = push(top, "https://proproprogs.ru/c_base/c_lokalnye-i-globalnye-peremennye");
    top = push(top, "https://proproprogs.ru/c_base/c_perechisleniya-enum-direktiva-typedef");

     while(top)
        top = pop(top);
    
    return 0;
}