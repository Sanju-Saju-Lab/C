#include <stdio.h>
#include <stdlib.h>

// Define a Node structure to represent each element in the doubly linked list.
typedef struct Node {
    int data;  // Data to store the value of the node.
    struct Node* next;  // Pointer to the next node in the list.
    struct Node* prev;  // Pointer to the previous node in the list.
} Node;

// Define a DLL structure to represent the doubly linked list itself.
typedef struct DLL {
    Node* head;  // Pointer to the first node in the list.
    Node* tail;  // Pointer to the last node in the list.
} DLL;

// Function to create a new empty doubly linked list.
DLL* createDLL() {
    DLL* dll = (DLL*)malloc(sizeof(DLL));  // Allocate memory for the list.
    dll->head = dll->tail = NULL;  // Initialize both head and tail to NULL (empty list).
    return dll;  // Return the newly created list.
}

// Function to append a new node at the end of the list.
void append(DLL* dll, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node.
    newNode->data = data;  // Set the node's data.
    newNode->next = NULL;  // The new node is the last node, so set next to NULL.

    // If the list is empty, the new node will be both the head and tail.
    if (dll->head == NULL) {
        dll->head = dll->tail = newNode;
        newNode->prev = NULL;  // Set the previous pointer of the first node to NULL.
    } else {
        newNode->prev = dll->tail;  // Set the previous pointer to the current tail.
        dll->tail->next = newNode;  // Set the current tail's next pointer to the new node.
        dll->tail = newNode;  // Update the tail to point to the new node.
    }
}

// Function to prepend a new node at the beginning of the list.
void prepend(DLL* dll, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node.
    newNode->data = data;  // Set the node's data.
    newNode->prev = NULL;  // The new node is the first node, so set prev to NULL.

    // If the list is empty, the new node will be both the head and tail.
    if (dll->head == NULL) {
        dll->head = dll->tail = newNode;
        newNode->next = NULL;  // Set the next pointer of the first node to NULL.
    } else {
        newNode->next = dll->head;  // Set the next pointer to the current head.
        dll->head->prev = newNode;  // Set the current head's previous pointer to the new node.
        dll->head = newNode;  // Update the head to point to the new node.
    }
}

// Function to insert a node at a specified position in the list.
void insertAtPosition(DLL* dll, int pos, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node.
    newNode->data = data;  // Set the node's data.

    // If inserting at the beginning, just use the prepend function.
    if (pos == 1) {
        prepend(dll, data);
        return;
    }

    Node* current = dll->head;
    int currentPosition = 1;
    
    // Traverse the list to find the node just before the specified position.
    while (current != NULL && currentPosition < pos - 1) {
        current = current->next;
        currentPosition++;
    }

    // If the position is invalid, print an error message.
    if (current == NULL) {
        printf("Invalid position.\n");
    } else if (current == dll->tail) {  // If the position is at the end, append the new node.
        append(dll, data);
    } else {  // Otherwise, insert the new node at the specified position.
        newNode->next = current->next;  // Set new node's next pointer to the next node.
        current->next->prev = newNode;  // Set the next node's prev pointer to the new node.
        current->next = newNode;  // Set current node's next pointer to the new node.
        newNode->prev = current;  // Set the new node's prev pointer to the current node.
    }
}

// Function to delete the first node in the list.
void deleteFirst(DLL* dll) {
    if (dll->head == NULL) {  // If the list is empty, print an error message.
        printf("List is empty.\n");
        return;
    }

    // If the list has only one node, free the node and reset both head and tail to NULL.
    if (dll->head == dll->tail) {
        free(dll->head);
        dll->head = dll->tail = NULL;
    } else {
        Node* temp = dll->head;
        dll->head = dll->head->next;  // Set head to the next node.
        dll->head->prev = NULL;  // Set the new head's prev pointer to NULL.
        free(temp);  // Free the old head node.
    }
}

// Function to delete the last node in the list.
void deleteLast(DLL* dll) {
    if (dll->tail == NULL) {  // If the list is empty, print an error message.
        printf("List is empty.\n");
        return;
    }

    // If the list has only one node, free the node and reset both head and tail to NULL.
    if (dll->head == dll->tail) {
        free(dll->tail);
        dll->head = dll->tail = NULL;
    } else {
        Node* temp = dll->tail;
        dll->tail = dll->tail->prev;  // Set tail to the previous node.
        dll->tail->next = NULL;  // Set the new tail's next pointer to NULL.
        free(temp);  // Free the old tail node.
    }
}

// Function to delete a node at a specified position in the list.
void deleteNode(DLL* dll, int pos) {
    if (dll->head == NULL) {  // If the list is empty, print an error message.
        printf("List is empty.\n");
        return;
    }

    // If deleting the first node, just use the deleteFirst function.
    if (pos == 1) {
        deleteFirst(dll);
        return;
    }

    Node* current = dll->head;
    int currentPosition = 1;

    // Traverse the list to find the node at the specified position.
    while (current != NULL && currentPosition < pos) {
        current = current->next;
        currentPosition++;
    }

    // If the position is invalid, print an error message.
    if (current == NULL) {
        printf("Invalid position.\n");
    } else if (current == dll->tail) {  // If the position is the last node, delete the last node.
        deleteLast(dll);
    } else {  // Otherwise, delete the node at the specified position.
        current->prev->next = current->next;  // Skip over the current node.
        current->next->prev = current->prev;  // Connect the previous node to the next node.
        free(current);  // Free the deleted node.
    }
}

// Function to traverse the list from head to tail and print the data of each node.
void traverseForward(DLL* dll) {
    if (dll->head == NULL) {  // If the list is empty, print a message.
        printf("List is empty.\n");
        return;
    }

    Node* current = dll->head;
    
    // Traverse the list and print each node's data.
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");  // Print a newline after printing all nodes.
}

// Function to traverse the list from tail to head and print the data of each node.
void traverseBackward(DLL* dll) {
    if (dll->tail == NULL) {  // If the list is empty, print a message.
        printf("List is empty.\n");
        return;
    }

    Node* current = dll->tail;
    
    // Traverse the list backward and print each node's data.
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");  // Print a newline after printing all nodes.
}

// Main function where the user can interact with the doubly linked list.
int main() {
    DLL* dll = createDLL();  // Create a new doubly linked list.
    int choice = 1, data, position;

    // Insert elements into the list interactively at the beginning.
    while (choice == 1) {
        printf("Enter the data: ");
        scanf("%d", &data);
        append(dll, data);  // Append the data at the end of the list.
        printf("Do you want to insert more elements? 0(No) or 1(Yes): ");
        scanf("%d", &choice);
    }

    traverseForward(dll);  // Display the list in forward order.

    // Display the menu for further operations.
    while (1) {
        printf("\nDoubly Linked List Menu\n");
        printf("1. Insert at the beginning.\n");
        printf("2. Insert at the end.\n");
        printf("3. Insert at a specified position.\n");
        printf("4. Remove from the beginning.\n");
        printf("5. Remove from the end.\n");
        printf("6. Remove from a specified position.\n");
        printf("7. Traverse Forward\n");
        printf("8. Traverse Backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        int menuChoice;
        scanf("%d", &menuChoice);

        // Execute the chosen operation based on user input.
        switch(menuChoice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                prepend(dll, data);  // Insert at the beginning.
                traverseForward(dll);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                append(dll, data);  // Insert at the end.
                traverseForward(dll);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(dll, position, data);  // Insert at the specified position.
                traverseForward(dll);
                break;
            case 4:
                deleteFirst(dll);  // Remove from the beginning.
                traverseForward(dll);
                break;
            case 5:
                deleteLast(dll);  // Remove from the end.
                traverseForward(dll);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteNode(dll, position);  // Remove from the specified position.
                traverseForward(dll);
                break;
            case 7:
                printf("Traverse Forward:\n");
                traverseForward(dll);  // Traverse and print forward.
                break;
            case 8:
                printf("Traverse Backward:\n");
                traverseBackward(dll);  // Traverse and print backward.
                break;
            case 9:
                printf("Exited\n");
                return 0;  // Exit the program.
            default:
                printf("Invalid choice. Please try again.\n");  // Handle invalid input.
        }
    }

    return 0;  // End the program.
}
