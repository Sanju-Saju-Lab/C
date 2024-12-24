#include <stdio.h>

#define MAX_SIZE 10  // Maximum size of the queue

// Define the structure for the queue
typedef struct {
    int queue[MAX_SIZE];  // Array to store the queue elements
    int front;  // Front pointer, initialized to -1 when the queue is empty
    int rear;   // Rear pointer, initialized to -1 when the queue is empty
} QueueArray;

// Enqueue operation - Adds an element to the queue
void enqueue(QueueArray* q, int element) {
    if (q->rear == MAX_SIZE - 1) {  // Check if the queue is full
        printf("Queue is full. Cannot add element: %d\n", element);
        return;
    }
    if (q->front == -1 && q->rear == -1) {  // If the queue is empty
        q->front = 0;  // Set front to the first index
        q->rear = 0;   // Set rear to the first index
    } else {
        q->rear++;  // Increment rear pointer to add the new element
    }
    q->queue[q->rear] = element;  // Add the element at the rear position
    printf("Enqueued: %d\n", element);  // Confirm the element was added
}

// Dequeue operation - Removes and returns the front element of the queue
int dequeue(QueueArray* q) {
    if (q->front == -1 && q->rear == -1) {  // Check if the queue is empty
        printf("Queue is empty. Cannot remove element.\n");
        return -1;  // Return -1 if the queue is empty
    }
    int element = q->queue[q->front];  // Get the front element
    q->front++;  // Move the front pointer to the next element
    if (q->front > q->rear) {  // If the queue becomes empty after dequeue
        q->front = -1;  // Reset front pointer
        q->rear = -1;   // Reset rear pointer
    }
    return element;  // Return the dequeued element
}

// Peek operation - Returns the front element without removing it
int peek(QueueArray* q) {
    if (q->front == -1 && q->rear == -1) {  // Check if the queue is empty
        printf("Queue is empty. Nothing to peek.\n");
        return -1;  // Return -1 if the queue is empty
    }
    return q->queue[q->front];  // Return the front element without removing it
}

// Display operation - Displays all the elements in the queue
void display(QueueArray* q) {
    if (q->front == -1 && q->rear == -1) {  // Check if the queue is empty
        printf("Queue is empty.\n");  // Inform the user that the queue is empty
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {  // Loop through the elements from front to rear
        printf("%d ", q->queue[i]);  // Print each element
    }
    printf("\n");  // Print a newline after displaying all elements
}

int main() {
    QueueArray q = {{0}, -1, -1};  // Initialize the queue with empty values
    int choice;
    while (1) {  // Infinite loop to allow repeated operations
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nYour choice: ");
        scanf("%d", &choice);  // Get user's choice

        switch (choice) {
            case 1:  // Enqueue operation
                {
                    int element;
                    printf("Enter element to enqueue: ");
                    scanf("%d", &element);  // Get the element from the user
                    enqueue(&q, element);  // Call the enqueue function
                    break;
                }
            case 2:  // Dequeue operation
                {
                    int dequeuedElement = dequeue(&q);  // Call dequeue function to remove an element
                    if (dequeuedElement != -1) {  // If element is successfully dequeued
                        printf("Dequeued: %d\n", dequeuedElement);  // Display the dequeued element
                    }
                    break;
                }
            case 3:  // Peek operation
                {
                    int peekedElement = peek(&q);  // Call peek function to view the front element
                    if (peekedElement != -1) {  // If there is an element to peek
                        printf("Front element: %d\n", peekedElement);  // Display the front element
                    }
                    break;
                }
            case 4:  // Display operation
                display(&q);  // Call display function to show all elements in the queue
                break;
            case 5:  // Exit operation
                printf("Exiting program. Goodbye!\n");  // Exit the program
                return 0;  // End the program
            default:  // Invalid choice
                printf("Invalid choice. Please try again.\n");  // Prompt the user to try again
        }
    }
}
