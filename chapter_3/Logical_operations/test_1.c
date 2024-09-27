#include <stdio.h>

int main(void)
{
    int rect_width = 640, rect_height = 480;
    int w = 1, h = 1;
    scanf("%d; %d", &w, &h);

    // здесь продолжайте программу
    // проверяем есть ли остаток по ширине и по длине
    _Bool corner = rect_width % w != 0 && rect_height % h != 0;
    
    _Bool x = rect_width % w != 0;      // есть ли остаток по ширине
    _Bool y = rect_height % h != 0;     // есть ли остаток по длине
    int result = rect_width / w * y + rect_height / h * x + corner;

    printf("%d", result);

    return 0;
}