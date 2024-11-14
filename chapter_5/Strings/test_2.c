#include <stdio.h>

int main(void)
{
    // здесь продолжайте программу
    char str[50] = "best string!";
    int NUM = sizeof(str) / sizeof(*str);

    // Вставляем 4 символа
    for (int i = 0; i < 4; ++i) {
        // Сдвигаем все эл-ты на 1 вправо
        for(int j = NUM-1; j > i; --j) {
            str[j] = str[j-1];
        }
        // Вставляем по 1 символу
        switch (i) {
            case 0:
                str[i] = 'T';
                break;
            case 1:
                str[i] = 'h';
                break;
            case 2:
                str[i] = 'e';
                break;
            case 3:
                str[i] = ' ';
                break;          
            default:
                break;
        }
    }

    puts(str);
    
 //   __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}