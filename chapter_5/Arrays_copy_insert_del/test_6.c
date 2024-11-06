/*
    Из массива pows необходимо удалить все элементы кратные 3 (делятся нацело на 3).
    Если таких элементов нет, то ничего удалять не нужно.
    Выведите в консоль по порядку в одну строчку через пробел полученные значения
    оставшихся элементов массива pows.
*/
#include <stdio.h>

#define TOTAL     20

int main(void)
{
    short pows[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(pows) / sizeof(*pows);

    while(count < sz_ar && scanf("%hd", &pows[count]) == 1)
        count++;
    
    // здесь продолжайте программу

    int temp = count;
    // Хитрость: считаем массив с конца, чтобы избежать наложения эл-тов после удаления
    for (int i = count-1; i >= 0; --i) {
        if(pows[i] % 3 == 0) {
            for(int j = i; j < count-1; ++j) {
                pows[j] = pows[j+1];
            //    printf("pows[%d] = pows[%d]\n", j, j+1);
            }
        --temp;
        }
    }

    for (int i = 0; i < temp; ++i)
        printf("%d ", pows[i]);
    
    return 0;
}