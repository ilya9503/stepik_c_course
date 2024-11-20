#include <stdio.h>
#include <string.h>

int main(void)
{
    // здесь продолжайте программу
    char ps[7][50] = {0};

    int num_i = sizeof(ps) / sizeof(ps[0]);
    int num_j = sizeof(ps[0]) / sizeof(ps[0][0]);

    for (int i = 0; i < num_i; ++i) {
        scanf("%49s ", ps[i]);
    }

    int num_res = (num_i*num_j) + 7;
    char ps_res[num_res];
    int max_len = num_res-1;

    for (int i = 0; i < num_i; ++i) {
        strcat(ps_res, ps[i]);
        if(i < (num_i - 1))
            strncat(ps_res, " ", max_len);
    }
    ps_res[max_len] = '\0';

    puts(ps_res);
    
    return 0;
}