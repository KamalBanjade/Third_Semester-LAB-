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
    printf("Values stored before realloc: ");
    for (int i = 0; i < size; i++) {
        ptr[i] = i + 1;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Reallocating memory for an array of 10 integers
    ptr = (int *)realloc(ptr, 10 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1; // Exit the program if reallocation fails
    }

    // Displaying the values stored in the reallocated memory
    printf("Values stored after realloc: ");
    for (int i = 0; i < 10; i++) {
        ptr[i] = i + 1;
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Freeing the allocated memory
    free(ptr);

    return 0;
}
