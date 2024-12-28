#include <stdio.h>

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the partition index (pivot is placed in the correct position)
        int pi = partition(arr, low, high);
        // Recursively sort the left sub-array (elements before the pivot)
        quickSort(arr, low, pi - 1);
        // Recursively sort the right sub-array (elements after the pivot)
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array into two parts based on the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // The pivot is the last element in the array
    int i = low - 1;        // Index of the smaller element, initially one before the first element

    // Loop through the array and rearrange elements
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // If the current element is smaller than the pivot
            i++;  // Increment the index of the smaller element
            // Swap the current element with the element at index i
            swap(&arr[i], &arr[j]);
        }
    }
    // Place the pivot element in its correct position by swapping it with the element at i + 1
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // Return the partition index (pivot's final position)
}

// Function to swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;  // Store the value of a temporarily
    *a = *b;        // Assign the value of b to a
    *b = temp;      // Assign the temporary value (original a) to b
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // Print each element followed by a space
    }
    printf("\n");  // Print a newline after all elements
}

// Main function to input elements, perform sorting, and display the result
int main() {
    int n;
    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array to store the elements
    // Ask the user to input the elements of the array
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Take input for each element
    }

    // Call the quickSort function to sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
