#include <stdio.h>

#define MAX_SIZE 10  // Define the maximum size of the stack

// Stack structure to hold stack elements and the top index
struct Stack {
    int stack[MAX_SIZE];  // Array to store the stack elements
    int top;              // Index to keep track of the top element
};

// Function to initialize the stack
void initialize(struct Stack* s) {
    s->top = -1;  // Set the stack as empty by initializing top to -1
}

// Push operation to add an element to the stack
void push(struct Stack* s, int item) {
    if (s->top == MAX_SIZE - 1) {  // Check if the stack is full
        printf("Stack Overflow! Can't push %d\n", item);  // Show error if full
    } else {
        s->stack[++(s->top)] = item;  // Add the item and increment top
        printf("Pushed: %d\n", item);  // Show which item is pushed
    }
}

// Pop operation to remove and return the top element from the stack
int pop(struct Stack* s) {
    if (s->top == -1) {  // Check if the stack is empty
        printf("Stack Underflow! Can't pop.\n");  // Show error if empty
        return -1;  // Return -1 to indicate an error
    } else {
        return s->stack[(s->top)--];  // Return and remove the top item
    }
}

// Peek operation to view the top element of the stack without removing it
int peek(struct Stack* s) {
    if (s->top == -1) {  // Check if the stack is empty
        printf("Stack is empty!\n");  // Show error if empty
        return -1;  // Return -1 to indicate an error
    } else {
        return s->stack[s->top];  // Return the top element without removing it
    }
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;  // Return true if stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;  // Return true if stack is full
}

// Function to display all elements of the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {  // Check if the stack is empty
        printf("Stack is empty!\n");  // Show error if empty
    } else {
        printf("Stack (top to bottom): ");
        for (int i = 0; i <= s->top; i++) {  // Loop through and print elements
            printf("%d ", s->stack[i]);
        }
        printf("\n");  // End the line after displaying all elements
    }
}

int main() {
    struct Stack stack;  // Create a stack variable
    initialize(&stack);   // Initialize the stack to be empty

    while (1) {  // Infinite loop for repeated operations
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);  // Read the user's choice

        switch (choice) {
            case 1: {  // If user chooses push operation
                int value;
                printf("Enter the value to push: ");
                scanf("%d", &value);  // Read the value to push
                push(&stack, value);  // Call push function to add the element
                break;
            }
            case 2: {  // If user chooses pop operation
                int poppedValue = pop(&stack);  // Call pop function
                if (poppedValue != -1) {  // If pop is successful
                    printf("Popped: %d\n", poppedValue);  // Show the popped value
                }
                break;
            }
            case 3: {  // If user chooses peek operation
                int topValue = peek(&stack);  // Call peek function
                if (topValue != -1) {  // If peek is successful
                    printf("Top element: %d\n", topValue);  // Show the top element
                }
                break;
            }
            case 4:  // If user chooses display operation
                display(&stack);  // Call display function to show all elements
                break;
            case 5:  // If user chooses to exit
                printf("Exiting program.\n");  // Show exit message
                return 0;  // Exit the program
            default:  // If user enters an invalid option
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
