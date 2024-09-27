#include <stdio.h>

int main(void)
{
    int rect_width = 640, rect_height = 480;
    int w = 1, h = 1;
    scanf("%d; %d", &w, &h);
    //считаешь кол-во умещающихся прямоугольников по горизонтали и вертикали:
    int fitHorizontally = rect_width / w;
    int fitVertically = rect_height / h;
    
    //считаешь кол-во НЕ умещающихся по горизонтали и вертикали:
    int extraHorizontally = (rect_height % h != 0) * fitHorizontally;   // 1 или 0 * на количество
    int extraVertically = (rect_width % w != 0) * fitVertically;
    
    //считаешь кол-во не умещающихся И по горизонтали И по вертикали:
    
    int extraCorner = (rect_height % h != 0) && (rect_width % w != 0);
    
    //складываешь... профит!!:
    
    printf("%d", extraHorizontally + extraVertically + extraCorner);
    return 0;
}