#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

struct Stack {
    int data[SIZE];
    int top;
};

void init(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack){
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == SIZE-1;
}

void push(struct Stack *stack, int value) {
    if(isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int top(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

struct Queue {
    struct Stack s1;
    struct Stack s2;
};

void initQueue(struct Queue *q) {
    init(&q->s1);
    init(&q->s2);
}

void enqueue(struct Queue *q, int value) {
    push(&q->s1, value);
}

int dequeue(struct Queue *q) {
    if(isEmpty(&q->s2)) {
        while(!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    if (!isEmpty(&q->s2)) {
        return pop(&q->s2);
    }
    else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("dequeue element: %d\n", dequeue(&q));
    printf("dequeue element: %d\n", dequeue(&q));

    enqueue(&q, 4);

    printf("dequeue element: %d\n", dequeue(&q));
    printf("dequeue element: %d\n", dequeue(&q));
    printf("dequeue element: %d\n", dequeue(&q));


    return 0;
}