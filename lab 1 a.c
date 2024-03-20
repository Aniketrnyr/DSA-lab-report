#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
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

void push(struct Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return -1; // Returning -1 for simplicity, assuming stack doesn't contain negative values
    }
    return s->items[(s->top)--];
}

void display_top(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top of the stack: %d\n", s->items[s->top]);
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice, item;
    
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display top\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1)
                    printf("Popped item: %d\n", item);
                break;
            case 3:
                display_top(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

