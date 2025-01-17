#include <stdio.h>

typedef struct {
    int x;
    int y;
} POINT;

typedef struct {
    double mean_x;
    double mean_y;
} DATA;

DATA get_means(POINT ar[], size_t ar_len)
{
    DATA sum = {0, 0};
    for (int i = 0; i < ar_len; ++i) {
        sum.mean_x += ar[i].x;
        sum.mean_y += ar[i].y;
    }
    sum.mean_x /= ar_len;
    sum.mean_y /= ar_len;
    return sum;
}

int main(void)
{
    POINT points[20] = {[0].x = 5, [0].y = 7, [1].x = 21, [1].y = 14, [2].x = 11, [2].y = 54, [3].x = -25, [3].y = -11, [4].x = -10, [4].y = 15};
    int count = 5;
    size_t ar_sz = sizeof(points) / sizeof(*points);
    //while (count < ar_sz && scanf("%d %d", &points[count].x, &points[count].y) == 2)
    //    ++count;
    
    DATA res = get_means(points, count);
    
    printf("%.2f %.2f", res.mean_x, res.mean_y);
    
    return 0;
}