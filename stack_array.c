#include <stdio.h>

#define MAX_SIZE 10  // Maximum capacity of the stack

// Stack structure
struct Stack {
    int stack[MAX_SIZE];  // Array to store stack elements
    int top;              // Index of the top element
};

// Function to initialize the stack
void initialize(struct Stack* s) {
    s->top = -1;  // Initialize the stack as empty
}

// Push operation
void push(struct Stack* s, int item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow! Can't push %d\n", item);
    } else {
        s->stack[++(s->top)] = item;
        printf("Pushed: %d\n", item);
    }
}

// Pop operation
int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow! Can't pop.\n");
        return -1;
    } else {
        return s->stack[(s->top)--];
    }
}

// Peek operation
int peek(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return s->stack[s->top];
    }
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Display the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack (top to bottom): ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->stack[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;  // Create a stack with the fixed size
    initialize(&stack);   // Initialize the stack

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            }
            case 2: {
                int poppedValue = pop(&stack);
                if (poppedValue != -1) {
                    printf("Popped: %d\n", poppedValue);
                }
                break;
            }
            case 3: {
                int topValue = peek(&stack);
                if (topValue != -1) {
                    printf("Top element: %d\n", topValue);
                }
                break;
            }
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
