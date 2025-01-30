#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // Максимальный размер очереди

// Структура данных для очереди
typedef struct Queue {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

// Инициализация очереди
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Проверка на пустоту
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Проверка на полноту
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Добавление элемента в очередь
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Очередь полна\n");
        return;
    }
    if (q->front == -1) {  // Если очередь была пуста
        q->front = 0;
    }
    q->rear++;          // постфиксная форма, сначала присваивание, затем инкремент
    q->items[q->rear] = value;
}

// Удаление элемента из очереди
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Очередь пуста\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {  // Если в очереди один элемент
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Просмотр элемента в начале очереди
int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Очередь пуста\n");
        return -1;
    }
    return q->items[q->front];
}

// Пример работы с очередью
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Элемент в начале очереди: %d\n", front(&q));

    printf("Удален элемент: %d\n", dequeue(&q));
    printf("Удален элемент: %d\n", dequeue(&q));

    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Элемент в начале очереди: %d\n", front(&q));
    printf("Удален элемент: %d\n", dequeue(&q));
    printf("Удален элемент: %d\n", dequeue(&q));
    printf("Удален элемент: %d\n", dequeue(&q));
    printf("Элемент в начале очереди: %d\n", front(&q));

    return 0;
}
