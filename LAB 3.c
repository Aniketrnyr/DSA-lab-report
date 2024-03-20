#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int is_empty(struct Stack *s) {
    return s->top == -1;
}

int is_full(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char item) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(struct Stack *s) {
    if (is_empty(s))
        return '\0';
    return s->items[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0; // Assuming '(' has lowest precedence
}

void infix_to_postfix(char *infix, char *postfix) {
    struct Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];
        if (c >= '0' && c <= '9') {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard '('
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
        i++;
    }

    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Add null terminator to the end of the postfix string
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

