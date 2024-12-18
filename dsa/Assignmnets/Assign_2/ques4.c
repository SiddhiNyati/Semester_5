#include <stdio.h>
#include <stdlib.h>

#define MAX 100  
struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->top++;
        s->data[s->top] = value;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return -1; 
}
int peek(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1; 
}
void Span(int prices[], int span[], int n) {
    struct Stack st;
    initStack(&st);

    span[0] = 1;
    push(&st, 0);

    for (int i = 1; i < n; i++) {
        while (!isEmpty(&st) && prices[peek(&st)] <= prices[i]) {
            pop(&st);
        }

        span[i] = isEmpty(&st) ? (i + 1) : (i - peek(&st));

        push(&st, i);
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int prices[] = {50, 40, 30, 35, 37, 20, 35, 36};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    Span(prices, span, n);

    display(span, n);

    return 0;
}
