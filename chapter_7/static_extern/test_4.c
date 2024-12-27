#include <stdio.h>

int range(int start, int stop, int step)
{
    static int count;
    if(!count) {
        count += start;
        return count;
    }
    else if(count <= stop-step) {
        count += step;
        return count;
    }
    else {
        count = start;
        return count;
    }
}

int main(void)
{
    int start, stop, step;
    scanf("%d %d %d", &start, &stop, &step);

    for(int i = 0;i < 20; ++i)
        printf("%d ", range(start, stop, step));

    return 0;
}