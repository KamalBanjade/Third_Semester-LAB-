#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;            // Data stored in the node
    struct Node* prev;   // Pointer to the previous node
    struct Node* next;   // Pointer to the next node
};

// Function to traverse the linked list
void listTraversal(struct Node* head) {
    printf("Linked list: NULL<->");  // Print the beginning of the list
    struct Node* current = head;
    if (head != NULL) {
        do {
            printf("%d<->", current->data);  // Print the data of the current node
            current = current->next;  // Move to the next node
        } while (current != head);  // Loop until we come back to the start
    }
    printf("NULL\n");  // Print NULL to indicate the end of the list
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    if (newNode == NULL) {  // Check if memory allocation was successful
        printf("Memory allocation failed\n");  // Print an error message
        exit(1);  // Exit the program with an error code
    }
    newNode->data = data;  // Set the data of the new node
    newNode->prev = NULL;   // Set the prev pointer of the new node to NULL
    newNode->next = NULL;   // Set the next pointer of the new node to NULL
    return newNode;         // Return the newly created node
}

// Function to insert a node at the beginning
void insertAtFirst(struct Node** headRef, int data) {
    printf("Inserting %d at the beginning\n", data);  // Print a message indicating the insertion operation
    struct Node* newNode = createNode(data);  // Create a new node with the specified data
    if (*headRef == NULL) {  // If the list is empty
        *headRef = newNode;  // Set the new node as the head
        newNode->next = newNode;  // Circular linking
        newNode->prev = newNode;  // Circular linking
    } else {
        newNode->next = *headRef;  // Point the new node's next to the current head
        newNode->prev = (*headRef)->prev;  // Point the new node's prev to the last node
        (*headRef)->prev->next = newNode;  // Update the next of the last node
        (*headRef)->prev = newNode;  // Update the prev of the current head
        *headRef = newNode;  // Update the head pointer
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** headRef, int data) {
    printf("Inserting %d at the end\n", data);  // Print a message indicating the insertion operation
    if (*headRef == NULL) {  // If the list is empty, call insertAtFirst
        insertAtFirst(headRef, data);
        return;
    }
    struct Node* newNode = createNode(data);  // Create a new node with the specified data
    newNode->next = *headRef;  // Point the new node's next to the current head
    newNode->prev = (*headRef)->prev;  // Point the new node's prev to the last node
    (*headRef)->prev->next = newNode;  // Update the next of the last node
    (*headRef)->prev = newNode;  // Update the prev of the current head
}

// Function to insert a node at a specified index
void insertAtIndex(struct Node** headRef, int data, int index) {
    printf("Inserting %d at index %d\n", data, index);  // Print a message indicating the insertion operation
    if (index == 0) {  // If index is 0, call insertAtFirst
        insertAtFirst(headRef, data);
        return;
    }
    struct Node* current = *headRef;
    int i = 0;
    while (i < index - 1 && current->next != *headRef) {  // Traverse till the (index - 1)th node
        current = current->next;
        i++;
    }
    if (current->next == *headRef && i < index - 1) {  // If index is out of bounds, insert at the end
        insertAtEnd(headRef, data);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;  // Link the new node to the next node
    newNode->prev = current;        // Link the new node to the current node
    current->next->prev = newNode;  // Link the next node to the new node
    current->next = newNode;        // Link the current node to the new node
}

// Function to delete the first node
void deleteAtFirst(struct Node** headRef) {
    printf("Deleting node at the beginning\n");  // Print a message indicating the deletion operation
    if (*headRef == NULL) {  // Check if the list is empty
        printf("List is empty\n");  // Print an error message
        return;  // Return from the function
    }
    if ((*headRef)->next == *headRef) {  // If there's only one node
        free(*headRef);  // Free the memory allocated for the node
        *headRef = NULL;  // Set head to NULL
        return;
    }
    struct Node* last = (*headRef)->prev;  // Get the last node
    struct Node* temp = *headRef;  // Create a temporary pointer to store the address of the current head node
    *headRef = (*headRef)->next;  // Move the head pointer to the next node
    (*headRef)->prev = last;  // Set the prev pointer of the new head node to the last node
    last->next = *headRef;  // Set the next pointer of the last node to the new head node
    free(temp);  // Free the memory allocated for the previous head node
}

// Function to delete the last node
void deleteAtEnd(struct Node** headRef) {
    printf("Deleting node at the end\n");  // Print a message indicating the deletion operation
    if (*headRef == NULL) {  // Check if the list is empty
        printf("List is empty\n");  // Print an error message
        return;  // Return from the function
    }
    if ((*headRef)->next == *headRef) {  // If there's only one node
        free(*headRef);  // Free the memory allocated for the node
        *headRef = NULL;  // Set head to NULL
        return;
    }
    struct Node* last = (*headRef)->prev;  // Get the last node
    struct Node* temp = last;  // Create a temporary pointer to store the address of the last node
    last->prev->next = *headRef;  // Set the next pointer of the second last node to the head node
    (*headRef)->prev = last->prev;  // Set the prev pointer of the head node to the second last node
    free(temp);  // Free the memory allocated for the last node
}

// Function to delete a node at a specified index
void deleteAtIndex(struct Node** headRef, int index) {
    printf("Deleting node at index %d\n", index);  // Print a message indicating the deletion operation
    if (*headRef == NULL) {  // Check if the list is empty
        printf("List is empty\n");  // Print an error message
        return;  // Return from the function
    }
    if (index == 0) {  // If index is 0, call deleteAtFirst
        deleteAtFirst(headRef);
        return;
    }
    struct Node* current = *headRef;
    int i = 0;
    while (i < index && current->next != *headRef) {  // Traverse till the (index - 1)th node
        current = current->next;
        i++;
    }
    if (i < index) {  // If index is out of bounds
        printf("Index out of bounds\n");  // Print an error message
        return;  // Return from the function
    }
    struct Node* temp = current;  // Create a temporary pointer to store the address of the node to be deleted
    current->prev->next = current->next;  // Link the previous node to the next node
    current->next->prev = current->prev;  // Link the next node to the previous node
    if (temp == *headRef) {  // If the node to be deleted is the head
        *headRef = current->next;  // Move the head pointer to the next node
    }
    free(temp);  // Free the memory allocated for the node
}

int main() {  // Main function
    struct Node* head = NULL;  // Initialize the head pointer to NULL
    listTraversal(head);  // Perform list traversal operation

    insertAtFirst(&head, 1);  // Insert at the beginning
    listTraversal(head);  // Perform list traversal operation
    insertAtEnd(&head, 3);  // Insert at the end
    listTraversal(head);  // Perform list traversal operation
    insertAtIndex(&head, 2, 2);  // Insert at index 2
    listTraversal(head);  // Perform list traversal operation

    deleteAtFirst(&head);  // Delete node at the beginning
    listTraversal(head);  // Perform list traversal operation
    deleteAtEnd(&head);  // Delete node at the end
    listTraversal(head);  // Perform list traversal operation
    deleteAtIndex(&head, 1);  // Delete node at index 1
    listTraversal(head);  // Perform list traversal operation

    return 0;  // Return 0 to indicate successful execution
}
