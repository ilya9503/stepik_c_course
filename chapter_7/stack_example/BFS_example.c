#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 6  // Максимальное количество вершин

// Структура для очереди
typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
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

// Структура для представления графа
typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Функция для добавления ребра в граф
void addEdge(Graph *g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;  // Так как граф неориентированный
}

// Алгоритм поиска в ширину (BFS)
Queue bfs(Graph *g, int start, int goal) {
    bool visited[MAX_VERTICES] = {false};  // Массив для отслеживания посещенных вершин
    Queue q;
    initQueue(&q);
    
    enqueue(&q, start);
    visited[start] = true;
    
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("Посещена вершина: %c\n", current + 'A');  // Выводим вершину, как букву
        
        if (current == goal) {
            printf("Целевая вершина %c найдена.\n", goal + 'A');
            return q;
        }

        // Проходим по соседям текущей вершины
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }
    printf("Целевая вершина не найдена.\n");
    return q;
}

int main() {
    Graph g = {0};  // Инициализация графа
    Queue q;

    // Добавляем рёбра в граф
    addEdge(&g, 0, 1);  // A - B
    addEdge(&g, 0, 2);  // A - C
    addEdge(&g, 1, 3);  // B - D
    addEdge(&g, 1, 4);  // B - E

    int start = 0;  // Начальная вершина (A)
    int goal = 4;   // Целевая вершина (E)

    printf("Поиск в ширину от вершины %c до вершины %c:\n", start + 'A', goal + 'A');
    q = bfs(&g, start, goal);
    for (int i = 0; i < MAX_VERTICES; ++i) {
        printf("%d ", q.items[i]);
    }
    

    return 0;
}