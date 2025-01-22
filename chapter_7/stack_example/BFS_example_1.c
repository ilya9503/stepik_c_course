#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 6  // Максимальное количество вершин в графе
#define INF INT_MAX  // Используем максимально возможное значение для расстояний

// Структура для очереди
typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Инициализация очереди
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Проверка, пуста ли очередь
bool isEmpty(Queue *q) {
    return q->front == -1;
}

// Добавление элемента в очередь
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Извлечение элемента из очереди
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

// Структура для графа
typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Функция для добавления ребра в граф
void addEdge(Graph *g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;  // Так как граф неориентированный
}

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

int main() {
    Graph g = {0};  // Инициализация графа

    // Добавляем рёбра в граф
    addEdge(&g, 0, 1);  // A - B
    addEdge(&g, 0, 2);  // A - C
    addEdge(&g, 1, 3);  // B - D
    addEdge(&g, 1, 4);  // B - E

    int start = 0;  // Начальная вершина (A)
    int goal = 4;   // Целевая вершина (E)

    bfs_shortest_path(&g, start, goal);

    return 0;
}
