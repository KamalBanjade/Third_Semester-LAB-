#include <stdio.h>  
#include <stdlib.h> 

struct Node {  // Define a structure for a doubly linked list node
    int data;  // Data stored in the node
    struct Node* prev;  // Pointer to the previous node
    struct Node* next;  // Pointer to the next node
};

void listTraversal(struct Node* head) {  // Function to traverse the linked list
    printf("Linked list: NULL<->");  // Print the beginning of the list
    while (head != NULL) {  // Loop until NULL is reached
        printf("%d<->", head->data);  // Print the data of the current node
        head = head->next;  // Move to the next node
    }
    if (head == NULL) printf("NULL\n");  // Print NULL to indicate the end of the list
}
/*listTraversal(struct Node* head): This function is responsible for traversing the entire doubly linked list and printing its elements. It takes the head pointer of the list as input and iterates through the list, printing each node's data until it reaches the end.*/

struct Node* createNode(int data) {  // Function to create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    if (newNode == NULL) {  // Check if memory allocation was successful
        printf("Memory allocation failed\n");  // Print an error message
        exit(1);  // Exit the program with an error code
    }
    newNode->data = data;  // Set the data of the new node
    newNode->prev = NULL;  // Set the prev pointer of the new node to NULL
    newNode->next = NULL;  // Set the next pointer of the new node to NULL
    return newNode;  // Return the newly created node
}
/*createNode(int data): This function creates a new node with the specified data value. It allocates memory for the new node using malloc, initializes its data field with the provided value, and sets both prev and next pointers to NULL. If memory allocation fails, it prints an error message and exits the program.*/

struct Node* insertAtFirst(struct Node* head, int data) {  // Function to insert a node at the beginning
    printf("Inserting %d at the beginning\n", data);  // Print a message indicating the insertion operation
    struct Node* newNode = createNode(data);  // Create a new node with the specified data
    if (head != NULL) {  // Check if the list is not empty
        newNode->next = head;  // Point the next pointer of the new node to the current head node
        head->prev = newNode;  // Point the prev pointer of the current head node to the new node
    }
    printf("Insertion complete\n");  // Print a message indicating the completion of the insertion operation
    return newNode;  // Return the new head node
}
/*insertAtFirst(struct Node* head, int data): This function inserts a new node with the given data at the beginning of the doubly linked list. It first creates a new node using createNode, then adjusts pointers to insert the new node at the beginning. If the list is not empty, it updates the prev pointer of the previous head node to point to the new node.*/

void insertAtEnd(struct Node* head, int data) {  // Function to insert a node at the end
    printf("Inserting %d at the end\n", data);  // Print a message indicating the insertion operation
    struct Node* newNode = createNode(data);  // Create a new node with the specified data
    struct Node* temp = head;  // Create a temporary pointer to traverse the list
    while (temp->next != NULL) {  // Traverse the list until the last node is reached
        temp = temp->next;  // Move to the next node
    }
    temp->next = newNode;  // Point the next pointer of the last node to the new node
    newNode->prev = temp;  // Point the prev pointer of the new node to the last node
    printf("Insertion complete\n");  // Print a message indicating the completion of the insertion operation
}
/*insertAtEnd(struct Node* head, int data): This function inserts a new node with the given data at the end of the doubly linked list. It creates a new node using createNode and then traverses the list to find the last node. Once the last node is found, it updates pointers to insert the new node at the end.*/

void insertAtIndex(struct Node* head, int data, int index) {  // Function to insert a node at a specified index
    printf("Inserting %d at index %d\n", data, index);  // Print a message indicating the insertion operation
    struct Node* newNode = createNode(data);  // Create a new node with the specified data
    struct Node* p = head;  // Create a pointer to traverse the list
    int i = 0;  // Initialize a counter variable
    while (i != index - 1) {  // Traverse the list until the specified position or the end of the list is reached
        p = p->next;  // Move to the next node
        i++;  // Increment the counter variable
    }
    newNode->next = p->next;  // Point the next pointer of the new node to the node at the specified position
    p->next = newNode;  // Point the next pointer of the node at the specified position to the new node
    newNode->prev = p;  // Point the prev pointer of the new node to the node at the specified position
    printf("Insertion complete\n");  // Print a message indicating the completion of the insertion operation
}
/*insertAtIndex(struct Node* head, int data, int index): This function inserts a new node with the given data at the specified index in the doubly linked list. It first creates a new node using createNode and then traverses the list to find the node at the specified index. It then adjusts pointers to insert the new node at the specified index.*/

struct Node* deleteAtFirst(struct Node* head) {  // Function to delete the first node
    printf("Deleting node at the beginning\n");  // Print a message indicating the deletion operation
    if (head == NULL) {  // Check if the list is empty
        printf("List is empty\n");  // Print an error message
        return NULL;  // Return NULL
    }
    struct Node* temp = head;  // Create a temporary pointer to store the address of the current head node
    head = head->next;  // Move the head pointer to the next node
    if (head != NULL) {  // Check if the new head node is not NULL
        head->prev = NULL;  // Point the prev pointer of the new head node to NULL
    }
    free(temp);  // Free the memory allocated for the previous head node
    printf("Deletion complete\n");  // Print a message indicating the completion of the deletion operation
    return head;  // Return the new head node
}
/*deleteAtFirst(struct Node* head): This function deletes the first node from the doubly linked list. It first checks if the list is empty. If not, it adjusts pointers to remove the first node and updates the head pointer accordingly. It also frees the memory allocated for the deleted node.*/

void deleteAtEnd(struct Node* head) {  // Function to delete the last node
    printf("Deleting node at the end\n");  // Print a message indicating the deletion operation
    if (head == NULL) {  // Check if the list is empty
        printf("List is empty\n");  // Print an error message
        return;  // Return from the function
    }
    struct Node* temp = head;  // Create a temporary pointer to traverse the list
    while (temp->next != NULL) {  // Traverse the list until the last node is reached
        temp = temp->next;  // Move to the next node
    }
    if (temp->prev != NULL) {  // Check if the node to be deleted is not the only node in the list
        temp->prev->next = NULL;  // Point the next pointer of the second last node to NULL
    }
    free(temp);  // Free the memory allocated for the last node
    printf("Deletion complete\n");  // Print a message indicating the completion of the deletion operation
}
/*deleteAtEnd(struct Node* head): This function deletes the last node from the doubly linked list. It traverses the list to find the last node and adjusts pointers to remove it. It also frees the memory allocated for the deleted node.*/

void deleteAtPosition(struct Node* head, int position) {  // Function to delete a node at a specified position
    printf("Deleting node at position %d\n", position);  // Print a message indicating the deletion operation
    struct Node* p = head;  // Create a pointer to traverse the list
    int i = 0;  // Initialize a counter variable
    while (p != NULL && i < position) {  // Traverse the list until the specified position or the end of the list is reached
        p = p->next;  // Move to the next node
        i++;  // Increment the counter variable
    }
    if (p == NULL) {  // Check if the specified position is out of bounds
        printf("Index out of bounds\n");  // Print an error message
        return;  // Return from the function
    }
    if (p->prev != NULL) {  // Check if the node to be deleted is not the first node in the list
        p->prev->next = p->next;  // Point the next pointer of the previous node to the next node
    }
    if (p->next != NULL) {  // Check if the node to be deleted is not the last node in the list
        p->next->prev = p->prev;  // Point the prev pointer of the next node to the previous node
    }
    free(p);  // Free the memory allocated for the node to be deleted
    printf("Deletion complete\n");  // Print a message indicating the completion of the deletion operation
}
/*deleteAtPosition(struct Node* head, int position): This function deletes the node at the specified position in the doubly linked list. It traverses the list to find the node at the specified position and adjusts pointers to remove it. It also frees the memory allocated for the deleted node.*/

void display(struct Node* head) {  // Function to display the doubly linked list
    printf("Doubly Linked List: ");  // Print a message indicating the display operation
    while (head != NULL) {  // Loop until NULL is reached
        printf("%d <-> ", head->data);  // Print the data of the current node
        head = head->next;  // Move to the next node
    }
    printf("NULL\n");  // Print NULL to indicate the end of the list
}
/*display(struct Node* head): This function displays the elements of the doubly linked list. It iterates through the list and prints the data of each node until it reaches the end.*/

int main() {  // Main function
    struct Node* head = NULL;  // Initialize the head pointer to NULL
     listTraversal(head);  // Perform list traversal operation

    head = insertAtFirst(head, 1);  // Insert at the beginning
    display(head);  // Display the doubly linked list
    insertAtEnd(head, 3);  // Insert at the end
    display(head);  // Display the doubly linked list
    insertAtIndex(head, 2, 2);  // Insert at index 2
    display(head);  // Display the doubly linked list
    listTraversal(head);  // Perform list traversal operation

    head = deleteAtFirst(head);  // Delete node at the beginning
    display(head);  // Display the modified doubly linked list
    deleteAtEnd(head);  // Delete node at the end
    display(head);  // Display the modified doubly linked list
    listTraversal(head);  // Perform list traversal operation
    return 0;  // Return 0 to indicate successful execution
}
