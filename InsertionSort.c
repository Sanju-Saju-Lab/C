#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // Start from the second element
        int key = arr[i];  // Store the current element to be inserted
        int j = i - 1;  // Compare with the element before it

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j--;  // Move to the previous element
        }
        arr[j + 1] = key;  // Place the key at its correct position
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {  // Loop through each element of the array
        printf("%d ", arr[i]);  // Print the element followed by a space
    }
    printf("\n");  // Move to the next line after printing the array
}

int main() {
    int n;

    // Taking the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);  // Read the number of elements

    int arr[n];  // Declare an array of size n

    // Taking array elements as input from the user
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Read each element into the array
    }

    // Printing the original unsorted array
    printf("Original Array:\n");
    printArray(arr, n);

    // Perform Insertion Sort to sort the array
    insertionSort(arr, n);

    // Printing the sorted array
    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;  // Return 0 to indicate successful execution
}
