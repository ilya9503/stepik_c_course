#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>     // var function
#include <limits.h>
#define INF INT_MAX     // Используем максимально возможное значение для расстояний

enum {name_length=50, total_links=50, max_path_station=100, max_stations = 10};

// Структура данных для описания станции
typedef struct tag_station {
    char name[name_length];                 // название станции метро
    struct tag_station* links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;

// Структура данных для очереди
typedef struct Queue {
    char st_names[max_stations][name_length];
    int front, rear;
} Queue;

void initQueue(Queue *q);               // Инициализация очереди
int isEmpty(Queue *q);                  // Проверка на пустоту
int isFull(Queue *q);                   // Проверка на полноту
void enqueue(Queue *q, STATION* st);    // Добавление элемента в очередь
char* dequeue(Queue *q);                // Удаление элемента из очереди
char* front(Queue *q);                  // Просмотр элемента в начале очереди

void set_station_links(STATION* st, int count_links, ...);
void show(STATION *st);
void find_path(STATION* from, STATION* to, STATION *path[], int* count_st);





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

    // Выведем на экран связи между станциями
    //show(st);

    STATION* path[max_path_station];
    int count_st = 0;

    path[0] = &st[0];
    path[1] = &st[1];
    path[2] = &st[2];
    path[3] = &st[3];
    Queue q;
    initQueue(&q);
    enqueue(&q, path[0]);
    enqueue(&q, path[1]);
    enqueue(&q, path[2]);
    enqueue(&q, path[3]);
    printf("Элемент в начале очереди: %s\n", front(&q));
    printf("Удален элемент: %s\n", dequeue(&q));
    printf("Элемент в начале очереди: %s\n", front(&q));
    printf("Удален элемент: %s\n", dequeue(&q));
    printf("Элемент в начале очереди: %s\n", front(&q));

/*
    enqueue(&q, path[1]);
    enqueue(&q, path[2]);
    enqueue(&q, path[3]);
    
        Для примера ищем кратчайший маршрут от 1 станции до 6
        На выходе должны получить 1 3 6
     
    //find_path(&st[0], &st[5], path, &count_st);

    for (int i = 0; i < 10; ++i)
        printf("[%s] ", st[i].name);
*/
    // Проверка очереди
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}



// Инициализация очереди
void initQueue(Queue *q) {
    q->front = -1;  // индекс начала очереди
    q->rear = -1;   // индекс конца очедери
}

// Проверка на пустоту
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Проверка на полноту
int isFull(Queue *q) {
    return q->rear == max_stations - 1;
}

// Добавление элемента в очередь
void enqueue(Queue *q, STATION* st) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    /*
        1. Инкрементируем индекс конца очереди
        2. Добавляем данные в ячейку с индексом конца очереди
    */
    q->rear++;
    strncpy(q->st_names[q->rear], st->name, name_length);
}

// Удаление элемента из очереди
char* dequeue(Queue *q) {
    char* res;
    char temp[name_length] = "Queue is empty\n";
    res = temp;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return res;
    }
    // Запоминаем удаляемый элемент из начала очереди
    strncpy(res, q->st_names[q->front], name_length);
    // Если в очереди один элемент
    if (q->front == q->rear) {  
        q->front = q->rear = -1;
    }
    else
        q->front++;

    return res;
}

// Просмотр элемента в начале очереди
char* front(Queue *q) {
    char* res = "Queue is empty\n";
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return res;
    }
    return q->st_names[q->front];
}

/*
    Установка взаимосвязей между станциями
*/
void set_station_links(STATION* st, int count_links, ...)
{
    va_list arg;                      // указатель на параметр
    va_start(arg, count_links);       // получение адреса первого вариадического параметра
    st->count_links = count_links;
    for (int i = 0; i < count_links; ++i)
        st->links[i] = va_arg(arg, STATION*);
    
    va_end(arg);    
}

/*
    Вывод информации о соединениях между станциями
*/
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

/*
    Функция поиска кратчайшего маршрута от одной станции до другой
        from - начальная станция
        to - конечная станция
        path - массив указателей из станций метро кратчайшего маршрута (включая станции from и to)
        count_st - указатель на целочисленную переменную, хранящую общее число станций в найденном маршруте
*/
void find_path(STATION* from, STATION* to, STATION *path[], int* count_st)
{
    int distance[max_stations];  // Массив для хранения расстояний от start до каждой вершины
    int parent[max_stations];   // Массив для отслеживания родительских вершин
    
    for (int i = 0; i < max_stations; ++i) {
        distance[i] = INF;  // Инициализируем расстояния как бесконечность
        parent[i] = -1;  // Инициализируем родителей как -1 (отсутствие родителей)
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, from);
    from->fl_reserved = 1;
    distance[0] = 0;

    while (! isEmpty(&q)) {
        char* current = dequeue(&q);

        // Если мы достигли целевой вершины
        if (strcmp(current, to->name)) {
            printf("Кратчайший путь от %s до %s:\n", from->name, to->name);
        }

    }
    

}
/*
// Алгоритм поиска в ширину для нахождения кратчайшего пути
void bfs_shortest_path(Graph *g, int start, int goal) {
    bool visited[MAX_VERTICES] = {false};  // Массив для отслеживания посещённых вершин
    int distance[MAX_VERTICES];  // Массив для хранения расстояний от start до каждой вершины
    int parent[MAX_VERTICES];  // Массив для отслеживания родительских вершин

    for (int i = 0; i < MAX_VERTICES; i++) {
        distance[i] = INF;  // Инициализируем расстояния как бесконечность
        parent[i] = -1;  // Инициализируем родителей как -1 (отсутствие родителей)
    }

    Queue q;
    initQueue(&q);

    // Начальная вершина
    enqueue(&q, start);
    visited[start] = true;
    distance[start] = 0;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);

        // Если мы достигли целевой вершины
        if (current == goal) {
            printf("Кратчайший путь от %c до %c:\n", start + 'A', goal + 'A');
            int path[MAX_VERTICES];
            int pathLength = 0;
            int crawl = goal;

            // Восстанавливаем путь
            while (crawl != -1) {
                path[pathLength++] = crawl;
                crawl = parent[crawl];
            }

            // Выводим путь в обратном порядке
            for (int i = pathLength - 1; i >= 0; i--) {
                printf("%c ", path[i] + 'A');
            }
            printf("\n");
            return;
        }

        // Проверяем всех соседей текущей вершины
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                parent[i] = current;
                enqueue(&q, i);
            }
        }
    }

    printf("Путь не найден.\n");
}
*/