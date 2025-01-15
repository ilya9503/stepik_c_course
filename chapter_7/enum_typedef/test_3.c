#include <stdio.h>

typedef enum {_do=1, _re=2, _mi=3, _fa=4, _sol=5, _la=6, _si=7} NOTES;

int get_major(NOTES note)
{
    return note == _do || note == _mi || note == _sol;
}

int main(void)
{
    NOTES note[5] = {0};
    int count = 0;
    while(scanf("%d ", &note[count]) == 1 && count < 5) {
        if(note[count] <= 7 && note[count] >= 1)
            ++count;
        else {
            printf("Input out of bounds!");
            return 0;
        }
    }

    for (int i = 0; i < count; ++i) {
        if(get_major(note[i]))
            printf("%d ", note[i]);
    }
    
    return 0;
}