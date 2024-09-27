#include <stdio.h>

int main(void)
{
    /*
    int k, m;
    if(scanf("%d, %d", &k, &m) != 2) {
        printf("Input error.");
        return 0;
    }

    // здесь продолжайте программу
    int min = (k < m && k != m) ? k : m;
    printf("%d", min * min);
    */

    int x;
    if(scanf("%d", &x) != 1) {
        printf("Input error.");
        return 0;
    }

//    x = (x < 0 || x == 0) ? 0 : x;

    printf("%d", (x < 0 || x == 0) ? 0 : x);





    return 0;
}