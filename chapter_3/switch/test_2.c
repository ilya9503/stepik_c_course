#include <stdio.h>

int main(void)
{
    char symbol;
    if(scanf("%c", &symbol) != 1) {
        printf("Input error.");
        return 0;
    }

    // здесь продолжайте программу
    switch (symbol)
    {
    case 'a':
//        printf("%c", symbol -);
        break;
    default:
        printf("%c", symbol - 32);
        break;
    }

//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
    
}