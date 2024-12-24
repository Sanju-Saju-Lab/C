#include <stdio.h>

#define MAX_SIZE 10  // Maximum size of the queue

// Define a structure for the circular queue
typedef struct {
    int queue[MAX_SIZE];  // Array to store the queue elements
    int front, rear;      // Front and rear pointers for the queue
} CQueueArray;

// Initialize the queue (set front and rear to -1 indicating an empty queue)
void initQueue(CQueueArray* cqueue) {
    cqueue->front = cqueue->rear = -1;
}

// Enqueue operation (insert an element at the rear of the queue)
void enqueue(CQueueArray* cqueue, int value) {
    // Check if the queue is full
    if ((cqueue->rear + 1) % MAX_SIZE == cqueue->front) {
        printf("Queue is full!\n");  // Queue is full, cannot add more elements
    } else {
        // If the queue is empty, set front to 0
        if (cqueue->front == -1) {
            cqueue->front = 0;
        }
        // Update the rear pointer and add the new element
        cqueue->rear = (cqueue->rear + 1) % MAX_SIZE;
        cqueue->queue[cqueue->rear] = value;
        printf("%d enqueued.\n", value);  // Print a confirmation message
    }
}

// Dequeue operation (remove an element from the front of the queue)
void dequeue(CQueueArray* cqueue) {
    // Check if the queue is empty
    if (cqueue->front == -1) {
        printf("Queue is empty!\n");  // Queue is empty, nothing to dequeue
    } else {
        // Print the dequeued element and update the front pointer
        printf("%d dequeued.\n", cqueue->queue[cqueue->front]);
        // If the queue has only one element, reset the queue to empty
        if (cqueue->front == cqueue->rear) {
            cqueue->front = cqueue->rear = -1;
        } else {
            // Otherwise, move the front pointer to the next element
            cqueue->front = (cqueue->front + 1) % MAX_SIZE;
        }
    }
}

// Peek operation (view the element at the front of the queue without removing it)
void peek(CQueueArray* cqueue) {
    // Check if the queue is empty
    if (cqueue->front == -1) {
        printf("Queue is empty!\n");  // Queue is empty, no front element to show
    } else {
        printf("Front element is: %d\n", cqueue->queue[cqueue->front]);  // Show the front element
    }
}

// Display the queue elements
void display(CQueueArray* cqueue) {
    // Check if the queue is empty
    if (cqueue->front == -1) {
        printf("Queue is empty!\n");  // Queue is empty, nothing to display
    } else {
        int i = cqueue->front;
        printf("Queue elements: ");
        // Traverse the queue from front to rear and print each element
        while (i != cqueue->rear) {
            printf("%d ", cqueue->queue[i]);
            i = (i + 1) % MAX_SIZE;  // Move to the next element in the circular queue
        }
        // Print the last element at the rear
        printf("%d\n", cqueue->queue[cqueue->rear]);
    }
}

int main() {
    CQueueArray cqueue;  // Declare a variable of type CQueueArray to represent the queue
    int choice, value;

    initQueue(&cqueue);  // Initialize the queue

    // Loop to allow the user to choose operations
    do {
        // Display menu options
        printf("\nChoose an Operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Take user input for the choice

        // Perform the chosen operation
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);  // Take user input for the value to enqueue
                enqueue(&cqueue, value);  // Call the enqueue function
                break;
            case 2:
                dequeue(&cqueue);  // Call the dequeue function
                break;
            case 3:
                peek(&cqueue);  // Call the peek function
                break;
            case 4:
                display(&cqueue);  // Call the display function
                break;
            case 5:
                printf("Exiting...\n");  // Exit the program
                break;
            default:
                printf("Invalid choice! Please try again.\n");  // Handle invalid input
        }
    } while (choice != 5);  // Repeat the loop until the user chooses to exit

    return 0;
}
