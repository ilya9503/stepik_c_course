#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct tag_obj{
    struct tag_obj* next;
    char url[MAX_LEN];
} OBJ;

OBJ* push(OBJ* top, const char* url)
{
    OBJ *ptr = malloc(sizeof(OBJ));

    strncpy(ptr->url, url, MAX_LEN - 1);
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if(top == NULL)
        return top;

    OBJ *ptr_next = top->next;
    free(top);
    return ptr_next;
}

int main(void)
{
    OBJ *top = NULL;

    top = push(top, "https://proproprogs.ru/c_base/c_etapy-translyacii-programmy-v-mashinnyy-kod-standarty");
    top = push(top, "https://proproprogs.ru/c_base/c_struktura-i-ponimanie-raboty-programmy-hello-world");
    top = push(top, "https://proproprogs.ru/c_base/c_dvoichnaya-shestnadcaterichnaya-i-vosmerichnaya-sistemy-schisleniya");
    top = push(top, "https://proproprogs.ru/c_base/c_lokalnye-i-globalnye-peremennye");
    top = push(top, "https://proproprogs.ru/c_base/c_perechisleniya-enum-direktiva-typedef");
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать)

    while(top)
        top = pop(top);

    return 0;
}