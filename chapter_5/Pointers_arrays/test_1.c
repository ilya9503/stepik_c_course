/*
    В программе до функции main() объявлены два массива типа char с именами buff_1 и buff_2.
    Эти массивы скрыты в коде, но они существуют.
    Необходимо в функции main() объявить массив того же типа char с именем buffer
    длиной 128 элементов.
    Затем, сформировать указатель с именем ptr_ar на массив buffer.
    Используя ptr_ar выполнить последовательное копирование значений элементов
    из массивов buff_1 и buff_2 в массив buffer
    (то есть, оператор [] для массива buffer не применять).
    Гарантируется, что длины массива buffer достаточно для хранения двух массивов
    buff_1 и buff_2.
*/
#include <stdio.h>

char buff_1[5] = {'a', 'b', 'c', 'd', 'e'};
char buff_2[5] = {'f', 'g', 'h', 'i', 'j'};

int main(void)
{
    // здесь продолжайте программу
    char buffer[10];
    char *ptr_ar = buffer;

    int n_buff_1 = sizeof(buff_1) / sizeof(*buff_1);
    int n_buff_2 = sizeof(buff_2) / sizeof(*buff_2);
    int n_buffer = sizeof(buffer) / sizeof(*buffer);

    for (int i = 0; i < n_buff_1; ++i)
            *(ptr_ar + i) = *(buff_1 + i);
    for (int i = 0; i < n_buff_2; ++i)
            *(ptr_ar + (i + n_buff_1)) = *(buff_2 + i);


    for (int i = 0; i < n_buffer; ++i) {
            printf("%c ", buffer[i]);
    }
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}