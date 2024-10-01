#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    char arr[MAX]; 
    int top;       
} stack;

void initializeStack(stack *s) {
    s->top = -1; 
}

void push(stack *s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow. Cannot push %c.\n", value);
    } else {
        s->arr[++(s->top)] = value; 
    }
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow. Cannot pop.\n");
        return '\0';
    } else {
        return s->arr[(s->top)--]; 
    }
}

char top(stack *s) {
    if (s->top == -1) {
        return '\0';
    } else {
        return s->arr[s->top];
    }
}