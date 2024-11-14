#include <stdio.h>

int main(void)
{
    // здесь продолжайте программу
    char str[50] = "Best   language  \"C\"";
    int NUM = sizeof(str) / sizeof(str[0]);
    puts(str);

    // Удаляем лишние пробелы
    for (int i = 0; i < NUM; ++i) {
        if (str[i] == ' ') {
           for (int j = i; j < NUM-1; ++j) {
                str[j] = str[j+1];
            }
        }
    }

    // Вставляем вместо 1 пробела возврат каретки
    for (int i = 0; i < NUM; ++i) {

        if (str[i] == ' ') {
            // Удаляем пробел
            for (int j = i; j < NUM-1; ++j) {
                str[j] = str[j+1];
            }
            // Сдвигаем все эл-ты на 1 вправо
            for(int j = NUM-1; j > i; --j) {
               str[j] = str[j-1];
            }
            // Вствляем перенос строки
            str[i] = '\n'; 
        }
    }
    
    puts(str);

    return 0;
}