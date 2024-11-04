/*
    Необходимо в массиве buffer поменять местами первую половину прочитанных данных со второй половиной.
    Обратите внимание, что число прочитанных данных определяется переменной count.
    Причем, если count четное, то первая половина меняется со второй целиком, а если count нечетное,
    то центральный элемент должен оставаться на своем месте без изменений.
    Выведите в консоль в одну строчку через пробел первые count элементов полученного массива buffer.
*/
#include <stdio.h>

#define SIZE_BUFFER     128

int main(void)
{
    int buffer[SIZE_BUFFER];
    size_t count = 0;
    size_t sz_ar = sizeof(buffer) / sizeof(*buffer);

    while(count < sz_ar && scanf("%d", &buffer[count]) == 1)
        count++;
    //printf("%d", count);
    // здесь продолжайте программу
    int half_ar;
    
    if (count % 2 == 0)
        half_ar = count / 2;
    else
        half_ar = count / 2 + 1;

    // поочередная замена элементов массива
    for(int i = count-1; i >= half_ar; --i) {
        int temp = buffer[i];
        buffer[i] = buffer[i-half_ar];
        buffer[i-half_ar] = temp;
    }

    // выводим в консоль все значения массива
    for (int i = 0; i < count; ++i) {
        printf("%d ", buffer[i]);
    }    
   
    return 0;
}
