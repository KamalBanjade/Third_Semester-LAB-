#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int size = 5;

    // Allocating memory for an array of 5 integers initialized to zero
    ptr = (int *)calloc(size, sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit the program if allocation fails
    }

    // Displaying the values stored in the allocated memory
    printf("Values stored using calloc: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Freeing the allocated memory
    free(ptr);

    return 0;
}
