#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    // Loop through the array elements
    for (int i = 0; i < n - 1; i++) {
        // Assume the first unsorted element is the smallest
        int minIndex = i;

        // Loop through the remaining unsorted elements
        for (int j = i + 1; j < n; j++) {
            // If a smaller element is found, update minIndex
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // If the smallest element is not already in the correct position, swap it
        if (minIndex != i) {
            int temp = arr[i];  // Store the current element in a temporary variable
            arr[i] = arr[minIndex];  // Put the smallest element at the current position
            arr[minIndex] = temp;  // Place the previous element at the position of the smallest
        }
    }
}

int main() {
    int n;

    // Ask the user to input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Declare an array to store the elements
    int arr[n];

    // Ask the user to input each element for the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Store each element in the array
    }

    // Call the selectionSort function to sort the array
    selectionSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print each sorted element
    }

    return 0;
}
