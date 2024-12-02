#include <stdio.h>

int get_volume(int h, int w, int d)
{
    return h * w * d;
}


int main(void)
{
    // здесь продолжайте функцию main
    int height, width, depth, res;
    if (scanf("%d %d %d", &height, &width, &depth) != 3) {
        printf("Incorrect input!");
        return 0;
    }

    res = get_volume(height, width, depth);
    printf("%d", res);

    return 0;
}