#include <stdio.h>

typedef struct {
    int x;
    int y;
} POINT;

int rect_square(const POINT* p1, const POINT* p2)
{
    return (p2->x - p1->x) * (p2->y - p1->y);
}

int main(void)
{
    POINT p1, p2;
    scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    printf("%d", rect_square(&p1, &p2));
    return 0;
}