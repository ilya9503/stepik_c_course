#include <stdio.h>
#include <string.h>

int main(void)
{
    // здесь продолжайте программу
    char ps[7][50] = {0};
    char ps_res[357] = {0};
    for(int i = 0; i < 7; ++i)
    {
 //       scanf("%s", ps[i]);
        strcat(ps_res, ps[i]);
        strcat(ps_res, (i == 6) ? "\0" : " ");
    }
    puts(ps_res);
    
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}