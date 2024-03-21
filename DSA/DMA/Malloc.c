#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int size = 5;

    // Allocating memory for an array of 5 integers
    ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit the program if allocation fails
    }

    // Using the allocated memory
    for (int i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }

    // Displaying the values stored in the allocated memory
    printf("Values stored using malloc: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Freeing the allocated memory
    free(ptr);

    return 0;
}
