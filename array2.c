#include <stdio.h>

#define ROWS 4  // Define the number of rows in the 2D array
#define COLS 4  // Define the number of columns in the 2D array

int array[ROWS][COLS] = {0};  // 2D array initialized with 0

// Function to display all elements in the array
void traverse() {
    printf("Array elements:\n");
    // Loop through each row
    for (int i = 0; i < ROWS; i++) {
        // Loop through each column in the current row
        for (int j = 0; j < COLS; j++) {
            printf("%d ", array[i][j]);  // Print each element in the array
        }
        printf("\n");  // Move to the next line after printing a row
    }
}

// Function to insert a value at a specific row and column
void insert(int row, int col, int value) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid index.\n");
    } else {
        array[row][col] = value;  // Insert the value at the specified position
        printf("Element inserted successfully.\n");
    }
}

// Function to delete an element (set it to 0) at a specific row and column
void delete_element(int row, int col) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid index.\n");
    } else {
        array[row][col] = 0;  // Set the specified element to 0
        printf("Element deleted successfully.\n");
    }
}

// Function to search for an element by its row and column index
void search_by_index(int row, int col) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid index.\n");
    } else {
        printf("Element at [%d][%d]: %d\n", row, col, array[row][col]);  // Print the element at the given index
    }
}

// Function to search for an element by its value
void search_by_value(int value) {
    // Loop through each element in the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == value) {  // If the value is found
                printf("Value %d found at index [%d][%d].\n", value, i, j);  // Print the index where the value is found
                return;  // Exit the function once the value is found
            }
        }
    }
    printf("Value not found.\n");  // If the value is not found in the array
}

// Function to update an element at a specific row and column
void update(int row, int col, int value) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid index.\n");
    } else {
        array[row][col] = value;  // Update the element at the specified position
        printf("Element updated successfully.\n");
    }
}

// Main function to interact with the user and perform operations
int main() {
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");

        int choice;
        printf("Your Choice: ");
        scanf("%d", &choice);  // Take user input for the operation to perform
        
        if (choice == 1) {
            // Get row, column, and value to insert
            int row, col, value;
            printf("Enter row (0-%d): ", ROWS-1);
            scanf("%d", &row);
            printf("Enter column (0-%d): ", COLS-1);
            scanf("%d", &col);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(row, col, value);  // Call the insert function
        } else if (choice == 2) {
            // Get row and column to delete
            int row, col;
            printf("Enter row (0-%d): ", ROWS-1);
            scanf("%d", &row);
            printf("Enter column (0-%d): ", COLS-1);
            scanf("%d", &col);
            delete_element(row, col);  // Call the delete function
        } else if (choice == 3) {
            traverse();  // Call the traverse function to display the array
        } else if (choice == 4) {
            // Ask user whether to search by index or value
            int search_type;
            printf("Enter 1 to search by row and column, 2 by value: ");
            scanf("%d", &search_type);
            if (search_type == 1) {
                // Get row and column for searching
                int row, col;
                printf("Enter row (0-%d): ", ROWS-1);
                scanf("%d", &row);
                printf("Enter column (0-%d): ", COLS-1);
                scanf("%d", &col);
                search_by_index(row, col);  // Call the search by index function
            } else if (search_type == 2) {
                // Get value to search for
                int value;
                printf("Enter value to search: ");
                scanf("%d", &value);
                search_by_value(value);  // Call the search by value function
            } else {
                printf("Invalid option.\n");  // Handle invalid option
            }
        } else if (choice == 5) {
            // Get row, column, and new value to update
            int row, col, value;
            printf("Enter row (0-%d): ", ROWS-1);
            scanf("%d", &row);
            printf("Enter column (0-%d): ", COLS-1);
            scanf("%d", &col);
            printf("Enter new value: ");
            scanf("%d", &value);
            update(row, col, value);  // Call the update function
        } else if (choice == 6) {
            printf("Exiting program.\n");  // Exit the program
            break;
        } else {
            printf("Invalid choice. Please try again.\n");  // Handle invalid choice
        }
    }
    return 0;  // End of the program
}
