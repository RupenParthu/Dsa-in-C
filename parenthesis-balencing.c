#include <stdio.h>
#include <stdlib.h>
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
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->items[(s->top)--];
}

int isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

int isBalanced(char *expr) {
    Stack s;
    init(&s);
    int i, len = strlen(expr);
    for (i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            push(&s, c);
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), c))
                return 0;
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[MAX_SIZE] = "{[(a+b)*c]-d}";
    if (isBalanced(expr))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");
    return 0;
}
