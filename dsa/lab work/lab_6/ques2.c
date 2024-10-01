#include <stdio.h>
#include <stdbool.h>
#include "ques1.c" 
bool isOpeningBracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isClosingBracket(char c) {
    return (c == ')' || c == '}' || c == ']');
}

bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

bool areBracketsBalanced(char *expr) {
    stack s;
    initializeStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char current = expr[i];

        if (isOpeningBracket(current)) {
            push(&s, current);
        }
        else if (isClosingBracket(current)) {
            if (s.top == -1 || !isMatchingPair(pop(&s), current)) {
                return false;
            }
        }
    }

    return (s.top == -1);
}

int main() {
    char expr1[] = "())";
    char expr2[] = "{}([])";

    printf("Testing expression: %s\n", expr1);
    if (areBracketsBalanced(expr1)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    printf("Testing expression: %s\n", expr2);
    if (areBracketsBalanced(expr2)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}