#include <stdio.h>
#include <stdlib.h> // Include this header for malloc

int main() {
    
    // Define the structure for the doubly linked list node
    struct node {
        int data;
        struct node *next;
        struct node *prev;
    };

    // Initialize nodes
    struct node *head=NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // Allocate memory for each node
    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));

    // Assign data values to each node
    one->data = 1;
    two->data = 2;
    three->data = 3;

    // Connect nodes to form the doubly linked list
    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    // Save the address of the first node in the head pointer
    head = one;

    // You might want to free the allocated memory when done using it
    // free(one);
    // free(two);
    // free(three);

    return 0;
}
