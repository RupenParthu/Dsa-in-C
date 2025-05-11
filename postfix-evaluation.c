#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->items[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->items[(s->top)--];
}

int evaluatePostfix(char* expr) {
    Stack s;
    init(&s);
    int i, len = strlen(expr);
    for(i = 0; i < len; i++) {
        char c = expr[i];
        if(isdigit(c)) {
            push(&s, c - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;
            switch(c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char expr[MAX_SIZE] = "56+3*2-";
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}
