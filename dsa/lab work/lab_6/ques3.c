#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0'; 
}


char top(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0'; 
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initializeStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) { 
            postfix[j++] = current;
        } else if (current == '(') { 
            push(&s, current);
        } else if (current == ')') { 
            while (!isEmpty(&s) && top(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); 
        } else { 
            while (!isEmpty(&s) && precedence(top(&s)) >= precedence(current)) {
                postfix[j++] = pop(&s);
            }
            push(&s, current);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; 

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}