#include <stdio.h>

// Function to perform sequential search
int sequentialSearch(int arr[], int n, int key) {
    // Traverse through each element of the array
    for (int i = 0; i < n; i++) {
        // If the current element matches the key, return its index
        if (arr[i] == key) {
            return i;
        }
    }
    // If the key is not found, return -1
    return -1;
}

int main() {
    int arr[] = {3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 9; // Element to search

    // Perform sequential search
    int index = sequentialSearch(arr, n, key);

    // Check if element is found or not
    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
