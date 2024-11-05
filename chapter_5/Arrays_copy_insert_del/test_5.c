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
    int flag = 0;
    for (int i = 0; i < count; i++) {
        if (pows[i] % 2 == 0) {
            for (int j = i; j < count-1; ++j) {
                pows[j] = pows[j+1];
                flag = 1;
            //    printf("pows[%d] = pows[%d]\n", j, j+1);
            }
        break;
        }
    }

    for (int i = 0; i < (flag == 1 ? count-1 : count); i++) {
        printf("%d ", pows[i]);
    }
    
    return 0;
}