#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

struct CircularQueue {
    int front, rear;
    int arr[SIZE];
};

void initializeQueue(struct CircularQueue *q) {
    q->front = q->rear = -1;
}
void enQueue(struct CircularQueue *q, int value) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->rear + 1) % SIZE == q->front) {
        printf("\nQueue is Full");
        return;
    }
    else if (q->front == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = value;
    }
    else if (q->rear == SIZE - 1 && q->front != 0) {
        q->rear = 0;
        q->arr[q->rear] = value;
    }
    else {
        q->rear = (q->rear + 1) % SIZE;
        q->arr[q->rear] = value;
    }
    printf("\nInserted %d into the queue", value);
}

int deQueue(struct CircularQueue *q) {

    if (q->front == -1) {
        printf("\nQueue is Empty");
        return -1;
    }
    int data = q->arr[q->front];
    q->arr[q->front] = -1; 

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }

    else if (q->front == SIZE - 1) {
        q->front = 0;
    }

    else {
        q->front = (q->front + 1) % SIZE;
    }
    return data;
}

void displayQueue(struct CircularQueue *q) {
    if (q->front == -1) {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in the Circular Queue are: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
    }
    else {
        for (int i = q->front; i < SIZE; i++) {
            printf("%d ", q->arr[i]);
        }
        for (int i = 0; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
    }
}

int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    enQueue(&q, 14);
    enQueue(&q, 22);
    enQueue(&q, 13);
    enQueue(&q, -6);
    
    displayQueue(&q);

    printf("\nDeleted Value = %d", deQueue(&q));
    printf("\nDeleted Value = %d", deQueue(&q));

    displayQueue(&q);

    enQueue(&q, 9);
    enQueue(&q, 20);
    enQueue(&q, 5);

    displayQueue(&q);
    
    enQueue(&q, 30); 
    
    return 0;
}