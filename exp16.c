#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void reverseKElements(struct Queue* queue, int k) {
    if (k > queue->size || k <= 0) {
        printf("Invalid value of k\n");
        return;
    }
    
    int stack[k];
    int i;
    
    for (i = 0; i < k; i++) {
        stack[i] = dequeue(queue);
    }
    
    for (i = k - 1; i >= 0; i--) {
        enqueue(queue, stack[i]);
    }
    
    int remaining = queue->size - k;
    while (remaining--) {
        enqueue(queue, dequeue(queue));
    }
}

void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i, index = queue->front;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    int n, k, item;
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    struct Queue* queue = createQueue(n);
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        enqueue(queue, item);
    }
    
    printf("Enter value of k: ");
    scanf("%d", &k);
    
    printf("Original queue: ");
    printQueue(queue);
    
    reverseKElements(queue, k);
    
    printf("Queue after reversing first %d elements: ", k);
    printQueue(queue);
    
    return 0;
}
