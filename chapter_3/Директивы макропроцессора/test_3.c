#include <stdio.h>

#define MAX_WIDTH   256
#define MAX_HEIGHT  500

int main(void)
{
    double width, height;
    if (scanf("%lf %lf", &width, &height) != 2) {
        printf("Input error!");
        return 0;
    }
/*
    width > MAX_WIDTH ? width = MAX_WIDTH : width;
    height > MAX_HEIGHT ? height = MAX_HEIGHT : height;
*/
    if (width > MAX_WIDTH) 
        width = MAX_WIDTH;

    if (height > MAX_HEIGHT) 
        height = MAX_HEIGHT;

    printf("%.1f %.1f", width, height);    
    
    return 0;
}