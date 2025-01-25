#include <stdio.h>
#include <stdarg.h>
#include <string.h>

enum { name_length = 50, total_links = 50, max_path_station = 100 };

typedef struct tag_station {
    char name[name_length];                 
    struct tag_station* links[total_links]; 
    short count_links;                      
    char fl_reserved;                       
} STATION;

typedef struct {
    STATION* data[max_path_station];
    int front, rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

int is_full(Queue* q) {  
    return q->rear >= max_path_station;
}

void enqueue(Queue* q, STATION* station) {
    if (!is_full(q))
        q->data[q->rear++] = station;
}

STATION* dequeue(Queue* q) {
    return is_empty(q) ? NULL : q->data[q->front++];
}

void set_station_links(STATION* st, int count_links, ...) {
    va_list args;
    va_start(args, count_links);
    st->count_links = count_links;

    for (int i = 0; i < count_links; i++)
        st->links[i] = va_arg(args, STATION*);

    va_end(args);
}

void reconstruct_path(STATION* from, STATION* to, STATION* prev[], STATION* path[], int* count_st) {
    *count_st = 0;
    for (STATION* at = to; at != NULL; at = prev[at - from]) {
        path[(*count_st)++] = at;
    }

    for (int i = 0; i < *count_st / 2; i++) {
        STATION* temp = path[i];
        path[i] = path[*count_st - 1 - i];
        path[*count_st - 1 - i] = temp;
    }
}

void find_path(STATION* from, STATION* to, STATION* path[], int* count_st) {
    if (from == to) { 
        path[0] = from;
        *count_st = 1;
        return;
    }

    Queue queue;
    init_queue(&queue);

    STATION* prev[max_path_station] = { NULL };
    STATION* reset_list[max_path_station]; 

    int reset_count = 0;
    int found = 0; 

    enqueue(&queue, from);
    from->fl_reserved = 1;
    reset_list[reset_count++] = from;

    while (!is_empty(&queue) && !found) {
        STATION* current = dequeue(&queue);

        for (int i = 0; i < current->count_links; i++) {
            STATION* next = current->links[i];

            if (!next->fl_reserved) {
                next->fl_reserved = 1;  
                reset_list[reset_count++] = next;
                enqueue(&queue, next);
                prev[next - from] = current;

                if (next == to) {
                    found = 1;
                    break;
                }
            }
        }
    }

    if (found) {
        reconstruct_path(from, to, prev, path, count_st);
    } else {
        *count_st = 0;
    }

    for (int i = 0; i < reset_count; i++) {
        reset_list[i]->fl_reserved = 0;
    }
}

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

    set_station_links(&st[0], 2, &st[1], &st[2]);
    set_station_links(&st[1], 3, &st[0], &st[3], &st[4]);
    set_station_links(&st[2], 2, &st[0], &st[5]);
    set_station_links(&st[3], 2, &st[1], &st[5]);
    set_station_links(&st[4], 2, &st[1], &st[7]);
    set_station_links(&st[5], 4, &st[2], &st[3], &st[6], &st[8]);
    set_station_links(&st[6], 2, &st[5], &st[8]);
    set_station_links(&st[7], 2, &st[4], &st[8]);
    set_station_links(&st[8], 4, &st[5], &st[6], &st[7], &st[9]);
    set_station_links(&st[9], 1, &st[8]);

    STATION* path[max_path_station];
    int count_st = 0;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    //find_path(&st[0], &st[9], path, &count_st);
    //print_path(path, count_st);

    return 0;
}
