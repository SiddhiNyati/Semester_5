#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

struct Stack {
     int data[SIZE];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == SIZE -1;
}

void push (struct Stack *s, int value) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(struct Stack *s){
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int dequeue(struct Stack *s) {
    if(isEmpty(s)) {
        printf("queue is empty\n");
        return -1;
    }
    int ele = pop(s);
    if(isEmpty(s)) {
        return ele;
    }
    int temp = dequeue(s);

    push(s, ele);
    return temp;
}

int main() {
    struct Stack s;
    init(&s);

    push(&s, 12);
    push(&s, 22);
    push(&s, 23);
    push(&s, 24);
    push(&s, 25);

    int dequeue_ele = dequeue(&s);
    printf("Dequeue element: %d\n", dequeue_ele);

    return 0;
}

// enqueue: O(1)
//dequeue: O(n)