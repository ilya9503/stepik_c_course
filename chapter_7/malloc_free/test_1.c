#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*  memcpy()    */

int main(void)
{
    // здесь продолжайте программу
    short *data = malloc(4 * sizeof(short));
    short data_input[] = {-4, 3, 0, 100};
    size_t len = sizeof(data_input) / sizeof(*data_input);

    // 3 аргумент, количество выделенной памяти, а не размер массива!
    memcpy(data, data_input, 4 * sizeof(short));
/*
    for(int i = 0; i < len; ++i)
        data[i] = data_input[i];
*/
    for(int i = 0; i < len; ++i)
        printf("%hd ", data[i]);  
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    // здесь освобождайте память
    free(data);
    return 0;
}