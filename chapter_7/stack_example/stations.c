#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>     // var function

enum {name_length=50, total_links=50, max_path_station=100};

typedef struct tag_station {
    char name[name_length];                 // название станции метро
    struct tag_station* links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;

void set_station_links(STATION* st, int count_links, ...)
{
    va_list arg;                      // указатель на параметр
    va_start(arg, count_links);       // получение адреса первого вариадического параметра
    st->count_links = count_links;
    for (int i = 0; i < count_links; ++i)
        st->links[i] = va_arg(arg, STATION*);
    
    va_end(arg);    
}

/* Принимает массив структур и выводит информацию о соединениях между станциями */
void show(STATION *st){
  printf("   Станция   || Соединена с\n");   
  printf("====================================\n");
  for(int i = 0; i < 10; ++i){
    printf("%10s", st[i].name);
    if(st[i].count_links != 0){
      printf("   || ");
      for(int j = 0; j < st[i].count_links; ++j)
        printf("%s ", st[i].links[j]->name); 
    }
    putchar('\n');
  }
}

int main(void)
{
    STATION st[10] = {
        {"St #1", .count_links=0, .fl_reserved=0},
        {"St #2", .count_links=0, .fl_reserved=0},
        {"St #3", .count_links=0, .fl_reserved=0},
        {"St #4", .count_links=0, .fl_reserved=0},
        {"St #5", .count_links=0, .fl_reserved=0},
        {"St #6", .count_links=0, .fl_reserved=0},
        {"St #7", .count_links=0, .fl_reserved=0},
        {"St #8", .count_links=0, .fl_reserved=0},
        {"St #9", .count_links=0, .fl_reserved=0},
        {"St #10", .count_links=0, .fl_reserved=0},
    };

    // здесь описывайте связи между станциями метро
    set_station_links(&st[0], 2, &st[1], &st[2]);                   // 1    2 3
    set_station_links(&st[1], 3, &st[0], &st[3], &st[4]);           // 2    1 4 5
    set_station_links(&st[2], 2, &st[0], &st[5]);                   // 3    1 6
    set_station_links(&st[3], 2, &st[1], &st[5]);                   // 4    2 6
    set_station_links(&st[4], 2, &st[1], &st[7]);                   // 5    2 8
    set_station_links(&st[5], 4, &st[2], &st[3], &st[6], &st[8]);   // 6    3 4 7 9
    set_station_links(&st[6], 2, &st[5], &st[8]);                   // 7    6 9
    set_station_links(&st[7], 2, &st[4], &st[8]);                   // 8    5 9
    set_station_links(&st[8], 4, &st[5], &st[6], &st[7], &st[9]);   // 9    6 7 8 10
    set_station_links(&st[9], 1, &st[8]);                           // 10   9

    show(st);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}