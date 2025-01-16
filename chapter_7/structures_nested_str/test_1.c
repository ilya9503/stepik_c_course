#include <stdio.h>

struct tag_vector {
    short x; short y; short z;
};

int main(void)
{
    // здесь продолжайте функцию main
    struct tag_vector vector;
    scanf("%hd %hd %hd", &vector.x, &vector.y, &vector.z); 
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}