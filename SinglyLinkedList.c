#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Node
struct Node {
    int data;               // The data held by the node
    struct Node* next;      // Pointer to the next node in the list
};

// Insert a node at the beginning of the list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = data;  // Assign data to the new node
    newNode->next = *head;  // Point the new node to the current head
    *head = newNode;  // Update head to the new node
}

// Insert a node at the end of the list
void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = data;  // Assign data to the new node
    newNode->next = NULL;   // The new node will be the last node (next = NULL)

    if (*head == NULL) {
        *head = newNode;  // If the list is empty, make the new node the head
        return;
    }

    struct Node* current = *head;
    while (current->next) {
        current = current->next; // Traverse to the last node
    }
    current->next = newNode;  // Insert the new node at the end
}

// Insert a node at a specified position in the list
void insertAtPosition(struct Node** head, int data, int pos) {
    if (pos < 0) {
        printf("Position cannot be negative.\n");
        return;
    }

    if (pos == 0) {
        insertAtFirst(head, data);  // If position is 0, insert at the beginning
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* current = *head;
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL) {
            printf("Position exceeds the list\n");
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Position exceeds the list\n");
        return;
    }

    newNode->next = current->next;  // Link the new node to the next node
    current->next = newNode;  // Insert the new node at the specified position
}

// Remove the first node from the list
void removeAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty...\n");
        return;
    }

    printf("%d removed from the list\n", (*head)->data);
    struct Node* temp = *head;
    *head = (*head)->next;  // Update head to the next node
    free(temp);  // Free the memory of the removed node
}

// Remove the last node from the list
void removeAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty...\n");
        return;
    }

    if ((*head)->next == NULL) {
        removeAtFirst(head);  // If there's only one node, remove it
        return;
    }

    struct Node* current = *head;
    while (current->next && current->next->next) {
        current = current->next;  // Traverse to the second-to-last node
    }

    printf("%d removed from the list\n", current->next->data);
    free(current->next);  // Free memory of the last node
    current->next = NULL;  // Set the second-to-last node's next to NULL
}

// Remove a node at a specified position
void removeAtPosition(struct Node** head, int pos) {
    if (pos < 0) {
        printf("Position cannot be negative.\n");
        return;
    }

    if (pos == 0) {
        removeAtFirst(head);  // If position is 0, remove the first node
        return;
    }

    struct Node* current = *head;
    for (int i = 0; i < pos - 1; i++) {
        if (current == NULL) {
            printf("Position exceeds list\n");
            return;
        }
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position exceeds list\n");
        return;
    }

    printf("%d removed from the list\n", current->next->data);
    struct Node* temp = current->next;
    current->next = current->next->next;  // Remove the node at the specified position
    free(temp);  // Free memory of the removed node
}

// Display the entire linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);  // Print the data of each node
        current = current->next;  // Move to the next node
    }
    printf("null\n");  // Indicate the end of the list
}

int main() {
    struct Node* head = NULL;  // Initialize an empty list
    int choice = 1, data, pos;

    // Insert elements into the list
    printf("Enter elements to the list: \n");
    while (choice == 1) {
        printf("Enter data: ");
        scanf("%d", &data);
        insertAtLast(&head, data);  // Insert the data at the end of the list
        printf("Do you want to insert more elements to the list 0(No) or 1(Yes): ");
        scanf("%d", &choice);
    }

    printf("List after initial insertion: \n");
    display(head);  // Display the list after the initial insertion

    // Menu-driven program to perform operations on the linked list
    while (1) {
        printf("\nLinked list operations:\n");
        printf("1. Insert at the beginning.\n");
        printf("2. Insert at the end.\n");
        printf("3. Insert at a specified position.\n");
        printf("4. Remove from the beginning.\n");
        printf("5. Remove from the end.\n");
        printf("6. Remove from a specified position.\n");
        printf("7. Traverse.\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtFirst(&head, data);  // Insert at the beginning
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtLast(&head, data);  // Insert at the end
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, data, pos);  // Insert at a specified position
                break;
            case 4:
                removeAtFirst(&head);  // Remove from the beginning
                break;
            case 5:
                removeAtLast(&head);  // Remove from the end
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                removeAtPosition(&head, pos);  // Remove from a specified position
                break;
            case 7:
                display(head);  // Display the list
                break;
            case 8:
                exit(0);  // Exit the program
        }
    }

    return 0;
}
