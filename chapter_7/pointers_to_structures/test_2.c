#include <stdio.h>
#include <stdlib.h>

// здесь объявляйте структуру
typedef struct tag_rub {
    double ratio_usd;   // курс доллара к рублю (1$ = xx рублей)
    int rubs;           // количество рублей
} EXCH_STR;

int main(void)
{
    // здесь продолжайте функцию main
    EXCH_STR* account_r = malloc(sizeof(EXCH_STR)); // выделяем память из кучи для структуры
    account_r->ratio_usd = 91.32;
    scanf("%d", &account_r->rubs);

    printf("%.2f", account_r->rubs / account_r->ratio_usd);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать)
    free(account_r);
    return 0;
}