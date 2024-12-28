#include <stdio.h>

// Function to perform Bubble Sort on the given array
void bubbleSort(int arr[], int n) {
    // Outer loop: Repeats passes to move elements to their correct positions
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;  // Flag to check if any elements were swapped during this pass
        // Inner loop: Compares adjacent elements and swaps them if they are in the wrong order
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {  // If the current element is greater than the next
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Mark that a swap has occurred
            }
        }
        // If no elements were swapped, the array is already sorted, so break out of the loop early
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n;
    // Asking the user for the number of elements they want to sort
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array to hold the elements
    printf("Enter the elements: \n");
    // Reading the elements from the user and storing them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calling the bubbleSort function to sort the array
    bubbleSort(arr, n);

    // Displaying the sorted array to the user
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print each element of the sorted array
    }

    return 0;
}
