#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX_SIZE] = "(A+B)*C";
    char postfix[MAX_SIZE];

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
