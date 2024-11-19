#include <stdio.h>
#include <string.h>

int main(void)
{
    char cities[6][50];

    int num_i = sizeof(cities) / sizeof(cities[0]);
    int num_j = sizeof(cities[0]) / sizeof(cities[0][0]);
    size_t str_len[6] = {0};


    for (int i = 0; i < num_i; ++i) {
        scanf("%49s ", cities[i]);
        str_len[i] = strlen(cities[i]);
    }

    size_t max_len = str_len[0];
    int max_index = 0;
    // Ищем максимальную длину в массиве, запоминаем индекс
    for (int i = 0; i < num_i; ++i) {
        if(str_len[i] > max_len) {
            max_len = str_len[i];
            max_index = i;
        }
    }

    printf("%s", cities[max_index]);
    
    return 0;
}