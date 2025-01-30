#include <stdio.h>
#include <stdarg.h>
#include <string.h>

enum { name_length = 50, total_links = 50, max_path_station = 100 };

typedef struct tag_station {
    char name[name_length];                 // Название станции метро
    struct tag_station* links[total_links]; // Связи с соседними станциями
    short count_links;                      // Количество связей
    char fl_reserved;                       // Зарезервированная переменная
} STATION;

// Функция для установки связей между станциями
void set_station_links(STATION* st, int count_links, ...) {
    va_list args;
    va_start(args, count_links);

    st->count_links = count_links;
    for (int i = 0; i < count_links; i++) {
        st->links[i] = va_arg(args, STATION*);
    }

    va_end(args);
}

// Функция для вывода информации о станции и её связях
void print_station_info(STATION* st) {
    printf("Станция: %s\n", st->name);
    printf("Связи: ");
    for (int i = 0; i < st->count_links; i++) {
        printf("%s ", st->links[i]->name);
    }
    printf("\n");
}

int main() {
    // Инициализация станций метро
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

    // Устанавливаем связи между станциями в соответствии с изображением
    set_station_links(&st[0], 1, &st[1]); // St #1 <-> St #2
    set_station_links(&st[1], 3, &st[0], &st[2], &st[3]); // St #2 <-> St #1, St #3, St #4
    set_station_links(&st[2], 1, &st[1]); // St #3 <-> St #2
    set_station_links(&st[3], 2, &st[1], &st[5]); // St #4 <-> St #2, St #6
    set_station_links(&st[4], 2, &st[1], &st[5]); // St #5 <-> St #2, St #6
    set_station_links(&st[5], 4, &st[3], &st[4], &st[6], &st[8]); // St #6 <-> St #4, St #5, St #7, St #9
    set_station_links(&st[6], 1, &st[5]); // St #7 <-> St #6
    set_station_links(&st[7], 2, &st[8], &st[4]); // St #8 <-> St #9, St #5
    set_station_links(&st[8], 3, &st[5], &st[7], &st[9]); // St #9 <-> St #6, St #8, St #10
    set_station_links(&st[9], 1, &st[8]); // St #10 <-> St #9

    // Вывод информации о станциях
    for (int i = 0; i < 10; i++) {
        print_station_info(&st[i]);
    }

    return 0;
}
