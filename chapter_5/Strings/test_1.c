#include <stdio.h>

int main(void)
{
    // здесь продолжайте программу
    char str[100] = "Best string!";
    char *text[3]= {"language C","language C++","language Python"};
    int NUM = sizeof(str) / sizeof(*str);

    for (int i = 0; i < NUM; ++i) {
        if(str[i] == 's')
            ;
    }
    
 //   __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}