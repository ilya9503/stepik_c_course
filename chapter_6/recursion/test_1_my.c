#include <stdio.h>
#define MAX_RECURSION    4

void recursive(int val)
{

    if(val < MAX_RECURSION) {
        //val++;
        recursive(val+1);
        // Почему если тут printf ставишь 4 не отображается ??
    }
    printf("%d ", val);
}

int main(void)
{
    recursive(1);

    return 0;
}