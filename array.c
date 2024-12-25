#include <stdio.h>

#define MAX_SIZE 10 // Maximum size of the array

int array[MAX_SIZE]; // Array to store elements
int size = 0; // Current number of elements in the array

// Function to display all elements in the array
void traverse() {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]); // Print each element
    }
    printf("\n");
}

// Function to insert a new element at a specific index
void insert(int index, int value) {
    if (size >= MAX_SIZE) { // Check if the array is full
        printf("Array is full. Cannot insert new element.\n");
        return;
    }
    if (index < 0 || index > size) { // Check for a valid index
        printf("Invalid index.\n");
        return;
    }
    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value; // Insert the new element
    size++; // Increase the size of the array
    printf("Element inserted successfully.\n");
}

// Function to delete an element at a specific index
void deleteElement(int index) {
    if (index < 0 || index >= size) { // Check for a valid index
        printf("Invalid index.\n");
        return;
    }
    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--; // Decrease the size of the array
    printf("Element deleted successfully.\n");
}

// Function to search for an element by its index
void searchByIndex(int index) {
    if (index < 0 || index >= size) { // Check for a valid index
        printf("Invalid index.\n");
        return;
    }
    // Display the element at the specified index
    printf("Element at index %d: %d\n", index, array[index]);
}

// Function to search for an element by its value
void searchByValue(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) { // Check if the value matches
            printf("Value %d found at index %d.\n", value, i);
            return;
        }
    }
    // If the value is not found
    printf("Value not found.\n");
}

// Function to update an element at a specific index
void update(int index, int value) {
    if (index < 0 || index >= size) { // Check for a valid index
        printf("Invalid index.\n");
        return;
    }
    array[index] = value; // Update the element
    printf("Element updated successfully.\n");
}

// Main function to run the program
int main() {
    int choice; // Variable to store user choice
    while (1) { // Infinite loop for menu
        printf("\nChoose an operation:\n1. Insert\n2. Delete\n3. Traverse\n4. Search\n5. Update\n6. Exit\nYour Choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // Insert operation
            int index, value;
            printf("Enter index to insert (0-%d): ", MAX_SIZE - 1);
            scanf("%d", &index);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(index, value);
        } else if (choice == 2) { // Delete operation
            int index;
            printf("Enter index to delete: ");
            scanf("%d", &index);
            deleteElement(index);
        } else if (choice == 3) { // Traverse operation
            traverse();
        } else if (choice == 4) { // Search operation
            int searchType;
            printf("Enter 1 to search by index, 2 by value: ");
            scanf("%d", &searchType);
            if (searchType == 1) {
                int index;
                printf("Enter index to search: ");
                scanf("%d", &index);
                searchByIndex(index);
            } else if (searchType == 2) {
                int value;
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchByValue(value);
            } else {
                printf("Invalid option.\n");
            }
        } else if (choice == 5) { // Update operation
            int index, value;
            printf("Enter index to update: ");
            scanf("%d", &index);
            printf("Enter new value: ");
            scanf("%d", &value);
            update(index, value);
        } else if (choice == 6) { // Exit the program
            printf("Exiting program.\n");
            break;
        } else { // Handle invalid choices
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0; // End of program
}
