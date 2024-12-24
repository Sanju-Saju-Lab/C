#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int queue[MAX_SIZE];
    int front, rear;
} CQueueArray;

// Initialize the queue
void initQueue(CQueueArray* cqueue) {
    cqueue->front = cqueue->rear = -1;
}

// Enqueue operation
void enqueue(CQueueArray* cqueue, int value) {
    if ((cqueue->rear + 1) % MAX_SIZE == cqueue->front) {
        printf("Queue is full!\n");
    } else {
        if (cqueue->front == -1) {
            cqueue->front = 0;
        }
        cqueue->rear = (cqueue->rear + 1) % MAX_SIZE;
        cqueue->queue[cqueue->rear] = value;
        printf("%d enqueued.\n", value);
    }
}

// Dequeue operation
void dequeue(CQueueArray* cqueue) {
    if (cqueue->front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("%d dequeued.\n", cqueue->queue[cqueue->front]);
        if (cqueue->front == cqueue->rear) {
            cqueue->front = cqueue->rear = -1;
        } else {
            cqueue->front = (cqueue->front + 1) % MAX_SIZE;
        }
    }
}

// Peek operation
void peek(CQueueArray* cqueue) {
    if (cqueue->front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", cqueue->queue[cqueue->front]);
    }
}

// Display the queue
void display(CQueueArray* cqueue) {
    if (cqueue->front == -1) {
        printf("Queue is empty!\n");
    } else {
        int i = cqueue->front;
        printf("Queue elements: ");
        while (i != cqueue->rear) {
            printf("%d ", cqueue->queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", cqueue->queue[cqueue->rear]);
    }
}

int main() {
    CQueueArray cqueue;
    int choice, value;

    initQueue(&cqueue);

    do {
        printf("\nChoose an Operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&cqueue, value);
                break;
            case 2:
                dequeue(&cqueue);
                break;
            case 3:
                peek(&cqueue);
                break;
            case 4:
                display(&cqueue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
