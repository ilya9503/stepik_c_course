/*
    Необходимо из массива ar в обратном порядке (идя от последнего записанного значения к первому)
    скопировать прочитанные данные в массив marks (копирование выполнять от первого элемента к последнему),
    не выходя за пределы массива marks. То есть, в случае достижения последнего элемента массива marks,
    останавливать процедуру копирования.
    Вывести в консоль значения массива marks (от первого до последнего скопированного элемента) в одну строчку
    через пробел.
*/
#include <stdio.h>

int main(void)
{
    short ar[10], marks[5];
    size_t count = 0;
    size_t sz_ar = sizeof(ar) / sizeof(*ar);

    while(count < sz_ar && scanf("%hd", &ar[count]) == 1)
        count++;
    //printf("%d\n", count);
    // здесь продолжайте программу
    size_t sz_marks = sizeof(marks) / sizeof(*marks);
    int temp = count;
    
    for (int i = 0; i < sz_marks; ++i, --temp) {
        marks[i] = ar[temp-1];
    }

    for (int i = 0; i < sz_marks && i < count; ++i)
        printf("%d ", marks[i]);

    return 0;
}