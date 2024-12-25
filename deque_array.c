#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10  // Maximum size of the deque

// Define a structure to represent the deque
typedef struct {
    int deque[MAX_SIZE];  // Array to hold the deque elements
    int front, rear, size;  // Front and rear pointers, and size of the deque
} DequeArray;

// Check if the deque is empty
bool isEmpty(DequeArray *dq) {
    return dq->front == -1;  // The deque is empty if the front pointer is -1
}

// Check if the deque is full
bool isFull(DequeArray *dq) {
    return (dq->rear + 1) % dq->size == dq->front;  // The deque is full if (rear + 1) % size equals front
}

// Insert a value at the front of the deque
void insertFront(DequeArray *dq, int value) {
    if (isFull(dq)) {
        printf("Overflow\n");  // Print overflow message if deque is full
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;  // If deque is empty, set both front and rear to 0
    } else {
        dq->front = (dq->front - 1 + dq->size) % dq->size;  // Move front pointer circularly
    }
    dq->deque[dq->front] = value;  // Insert the value at the front
}

// Insert a value at the rear of the deque
void insertRear(DequeArray *dq, int value) {
    if (isFull(dq)) {
        printf("Overflow\n");  // Print overflow message if deque is full
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;  // If deque is empty, set both front and rear to 0
    } else {
        dq->rear = (dq->rear + 1) % dq->size;  // Move rear pointer circularly
    }
    dq->deque[dq->rear] = value;  // Insert the value at the rear
}

// Delete an element from the front of the deque
void deleteFront(DequeArray *dq) {
    if (isEmpty(dq)) {
        printf("Underflow\n");  // Print underflow message if deque is empty
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // If only one element is left, reset front and rear to -1
    } else {
        dq->front = (dq->front + 1) % dq->size;  // Move front pointer circularly
    }
}

// Delete an element from the rear of the deque
void deleteRear(DequeArray *dq) {
    if (isEmpty(dq)) {
        printf("Underflow\n");  // Print underflow message if deque is empty
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // If only one element is left, reset front and rear to -1
    } else {
        dq->rear = (dq->rear - 1 + dq->size) % dq->size;  // Move rear pointer circularly
    }
}

// Display the elements of the deque
void display(DequeArray *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");  // Print message if deque is empty
        return;
    }
    int i = dq->front;
    printf("Deque: ");
    while (true) {
        printf("%d ", dq->deque[i]);  // Print the current element
        if (i == dq->rear) break;  // Stop if the rear is reached
        i = (i + 1) % dq->size;  // Move to the next element circularly
    }
    printf("\n");
}

int main() {
    DequeArray dq;
    dq.size = MAX_SIZE;  // Set the size of the deque
    dq.front = dq.rear = -1;  // Initialize front and rear pointers to -1 (empty deque)

    int dequeType;
    do {
        printf("Choose deque type:\n");
        printf("1. Input Restricted\n");
        printf("2. Output Restricted\n");
        printf("Your choice: ");
        scanf("%d", &dequeType);  // User input for deque type
    } while (dequeType < 1 || dequeType > 2);  // Ensure valid deque type choice

    while (true) {
        printf("\nChoose an operation:\n");
        if (dequeType == 1) {  // Input Restricted
            printf("1. Insert at Rear\n");
            printf("2. Delete from Front\n");
            printf("3. Delete from Rear\n");
        } else {  // Output Restricted
            printf("1. Insert at Front\n");
            printf("2. Insert at Rear\n");
            printf("3. Delete from Front\n");
        }
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);  // User input for operation choice

        if (choice == 5) break;  // Exit the loop if user chooses 5

        switch (choice) {
            case 1:
                printf("Enter value: ");
                int value;
                scanf("%d", &value);  // User input for value
                if (dequeType == 1)
                    insertRear(&dq, value);  // Insert at rear for input restricted deque
                else
                    insertFront(&dq, value);  // Insert at front for output restricted deque
                break;
            case 2:
                if (dequeType == 1)
                    deleteFront(&dq);  // Delete from front for input restricted deque
                else {
                    printf("Enter value: ");
                    scanf("%d", &value);  // User input for value
                    insertRear(&dq, value);  // Insert at rear for output restricted deque
                }
                break;
            case 3:
                if (dequeType == 1)
                    deleteRear(&dq);  // Delete from rear for input restricted deque
                else
                    deleteFront(&dq);  // Delete from front for output restricted deque
                break;
            case 4:
                display(&dq);  // Display the current elements in the deque
                break;
            default:
                printf("Invalid choice\n");  // Handle invalid user input
        }
    }

    return 0;
}
