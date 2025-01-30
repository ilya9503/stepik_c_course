#include <stdio.h>
#include <stdarg.h>
#include <string.h>

enum { name_length = 50, total_links = 50, max_path_station = 100 };

// Определяем структуру станции метро
typedef struct tag_station {
    char name[name_length];                 // Название станции
    struct tag_station* links[total_links]; // Связи с соседними станциями
    short count_links;                      // Количество связей
    char fl_reserved;                       // Флаг для поиска пути (0 - не посещена, 1 - посещена)
} STATION;

// Структура очереди для BFS
typedef struct {
    STATION* data[max_path_station]; // Массив указателей на станции
    int front, rear;                 // Индексы начала и конца очереди
} Queue;

// Инициализация очереди
void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

// Проверка, пуста ли очередь
int is_empty(Queue* q) {
    return q->front == q->rear;
}

// Проверка, заполнена ли очередь
int is_full(Queue* q) {  
    return q->rear >= max_path_station;
}

// Добавление станции в очередь
void enqueue(Queue* q, STATION* station) {
    if (!is_full(q))
        q->data[q->rear++] = station; // Добавляем элемент в конец
    else
        printf("Ошибка: Очередь переполнена!\n");
}

// Извлечение станции из очереди
STATION* dequeue(Queue* q) {
    return is_empty(q) ? NULL : q->data[q->front++]; // Убираем элемент из начала
}

// Установка связей между станциями (аргументы передаются списком)
void set_station_links(STATION* st, int count_links, ...) {
    va_list args;
    va_start(args, count_links);

    st->count_links = count_links;
    for (int i = 0; i < count_links; i++)
        st->links[i] = va_arg(args, STATION*);

    va_end(args);
}

// Восстановление пути из массива prev (идем от конечной станции к начальной)
void reconstruct_path(STATION* from, STATION* to, STATION* prev[], STATION* path[], int* count_st) {
    *count_st = 0;
    
    // Проходим по цепочке предков от конца к началу
    for (STATION* at = to; at != NULL; at = prev[at - from]) {
        path[(*count_st)++] = at;
    }

    // Разворачиваем массив path[], чтобы путь шел от from к to
    for (int i = 0; i < *count_st / 2; i++) {
        STATION* temp = path[i];
        path[i] = path[*count_st - 1 - i];
        path[*count_st - 1 - i] = temp;
    }
}

// Поиск кратчайшего пути с помощью BFS (поиск в ширину)
void find_path(STATION* from, STATION* to, STATION* path[], int* count_st) {
    // Если начальная и конечная станции совпадают, маршрут состоит из одной станции
    if (from == to) { 
        path[0] = from;
        *count_st = 1;
        return;
    }

    // Инициализация очереди для BFS
    Queue queue;
    init_queue(&queue);

    // Массив для хранения предшествующих станций (используется для восстановления пути)
    STATION* prev[max_path_station] = { NULL };

    // Массив для сброса флага посещения после поиска
    STATION* reset_list[max_path_station];
    int reset_count = 0; // Количество станций, чьи флаги нужно сбросить

    int found = 0; // Флаг, указывающий, найден ли путь

    // Добавляем начальную станцию в очередь
    enqueue(&queue, from);
    from->fl_reserved = 1; // Отмечаем начальную станцию как посещенную
    reset_list[reset_count++] = from; // Добавляем ее в список для сброса

    // Запускаем BFS
    while (!is_empty(&queue) && !found) {
        STATION* current = dequeue(&queue); // Извлекаем станцию из очереди

        // Перебираем все соседние станции
        for (int i = 0; i < current->count_links; i++) {
            STATION* next = current->links[i];

            // Проверяем, посещали ли эту станцию ранее
            if (!next->fl_reserved) {
                next->fl_reserved = 1; // Отмечаем как посещенную
                reset_list[reset_count++] = next; // Добавляем в список для сброса

                // Запоминаем, откуда мы пришли на эту станцию
                prev[next - from] = current;

                // Если мы нашли нужную станцию, завершаем поиск
                if (next == to) {
                    found = 1;
                    break;
                }

                // Добавляем станцию в очередь для дальнейшего обхода
                enqueue(&queue, next);
            }
        }
    }

    // Если путь найден, восстанавливаем его
    if (found)
        reconstruct_path(from, to, prev, path, count_st);
    else 
        *count_st = 0; // Если путь не найден, count_st = 0

    // Сбрасываем флаг посещенных станций
    for (int i = 0; i < reset_count; i++)
        reset_list[i]->fl_reserved = 0;
}

// Вывод маршрута
void print_path(STATION* path[], int count_st) {
    if (count_st == 0) {
        printf("Путь не найден.\n");
        return;
    }

    printf("Маршрут: ");
    for (int i = 0; i < count_st; i++) {
        printf("[%s] ", path[i]->name);
    }
    printf("\n");
}

int main() {
    // Создаем станции метро
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

    // Устанавливаем связи между станциями (граф)
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

    // Переменные для хранения пути
    STATION* path[max_path_station];
    int count_st = 0;

    // Поиск пути между станцией 1 и станцией 10
    find_path(&st[0], &st[9], path, &count_st);

    // Вывод найденного маршрута
    print_path(path, count_st);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}