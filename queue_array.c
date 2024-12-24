#include <stdio.h>

#define MAX_SIZE 10  // Define maximum size of the queue

// Queue structure
struct QueueArray {
    int queue[MAX_SIZE];  // Array to store queue elements
    int front;
    int rear;
    int size;
};

// Function to initialize the queue
void initialize(struct QueueArray* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Enqueue operation
void enqueue(struct QueueArray* q, int element) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full. Cannot add element: %d\n", element);
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->queue[q->rear] = element;
    q->size++;
    printf("Enqueued: %d\n", element);
}

// Dequeue operation
int dequeue(struct QueueArray* q) {
    if (q->size == 0) {
        printf("Queue is empty. Cannot remove element.\n");
        return -1;
    }
    int element = q->queue[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return element;
}

// Peek operation
int peek(struct QueueArray* q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->queue[q->front];
}

// Display the queue
void display(struct QueueArray* q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->queue[(q->front + i) % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    struct QueueArray queue;
    initialize(&queue);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element;
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            }
            case 2: {
                int dequeuedElement = dequeue(&queue);
                if (dequeuedElement != -1) {
                    printf("Dequeued: %d\n", dequeuedElement);
                }
                break;
            }
            case 3: {
                int peekElement = peek(&queue);
                if (peekElement != -1) {
                    printf("Front element: %d\n", peekElement);
                }
                break;
            }
            case 4:
                display(&queue);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
