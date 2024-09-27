#include <stdio.h>

int main(void)
{
    short item = 3;
    switch(item) {
        case 1: printf("one\n");
        case 2: printf("two\n");
        case 3: printf("three\n");
        case 4: printf("four\n");
        default: printf("other number\n");
    }
    return 0;
}