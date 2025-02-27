#include <iostream>

using type_sort = enum {sort_asc, sort_desc};

void swap(short& val1, short& val2)
{
    short temp = val1;
    val1 = val2;
    val2 = temp;
}

int sort(short* ar, size_t len, type_sort type=sort_asc)
{
    short ar_copy[len]{0};              // копия исходного массива
    for(int i = 0; i < len; ++i)
        ar_copy[i] = ar[i];


    for(int i = 0; i < len; ++i) {
        int index = i;
        for(int j = index; j < len; ++j) {
            switch (type) {
                case sort_desc:             // по убыванию
                    if(ar[j] > ar[index]) {
                        index = j;          // находим максимальный индекс
                    }
                    break;
                default:                    // по возрастанию
                    if(ar[j] < ar[index]) {
                        index = j;          // находим минимальный индекс
                    }
                    break;
            }
        }
        swap(ar[i], ar[index]);     // заменяем
    }

    int count = 0;                  // сравниваем отсортированный с исходным
    for(int i = 0; i < len; ++i) {
        if(ar[i] != ar_copy[i])
            ++count;
    }

    return count;
}


int main()
{
    short ar[]{-5, 4, 10, 0, -100, -1, -2, 98};
    int count = 0;
    count = sort(ar, sizeof(ar)/sizeof(*ar));

    for(short x : ar)
        std::cout << x << ' ';

    std::cout << std::endl << count << std::endl;

    return 0;
}