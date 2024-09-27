#include <stdio.h>
int max_val(int val1, int val2);
int main(void)
{
    int width, height;
    if(scanf("%d %d", &width, &height) != 2) {
        printf("Input error.");
        return 0;
    }
    
//    int border = max_val(width, height) + 8;
    int border = (width > height ? width : height) + 8;
    printf("%d", border);
//    (a == b && a > 0) ? printf("square") : printf("rectangle");

    return 0;
}

int max_val(int val1, int val2)
{
    if (val1 > val2) return val1;
    else if (val2 > val1) return val2;
    printf("val1 = val2\n");
    return val1; 
}