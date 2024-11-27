#include <stdio.h>

int main(void)
{
    int h = 0, m = 0, s = 0;
    char hh[3] = "--", mm[3] = "--", ss[3] = "--";
    char res_str[9] = {0};
    
    scanf("%2d %2d %2d", &h, &m, &s);
    // Если числа входят в диапазон, то сохраняем результат в строки hh mm ss
    if((0<=h) &&(h<=23)) sprintf(hh, "%02d", h);
    if((0<=m) &&(m<=59)) sprintf(mm, "%02d", m);
    if((0<=s) &&(s<=59)) sprintf(ss, "%02d", s);
    // Формируем общую строку. Если все ок, то отобразятся if, если нет то hh mm ss при объявлении
    sprintf(res_str, "%2s:%2s:%2s\0", hh, mm, ss);
    puts(res_str);

    return 0;
}