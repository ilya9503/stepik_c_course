/*
    Вложенная сумма
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
//    int total_boxes = 3;
//    int total_files = 6;
    int s = 0;
    
    // Пример вложенного цикла, для перебора файлов в коробках 
    // Работает только со скобками!!!
    for (int i = -3; i <= 7; ++i){
        for (int j = 1; j <= 5; ++j){
            for (int k = 2; k <= 4; ++k){
                s += pow(i + j - k, 2);
            }
        }
    }

    printf("%d", s);
    
    return 0;
}