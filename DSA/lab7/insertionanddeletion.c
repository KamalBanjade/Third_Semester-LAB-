#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct node* insertAtFirst(struct node* head, int data) {
    printf("Inserting %d at the beginning\n", data);
    struct node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node* head, int data) {
    printf("Inserting %d at the end\n", data);
    struct node* newNode = createNode(data);
    struct node* temp = head;  // Use a temporary variable for traversal
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specified index in the linked list
void insertAtPosition(struct node* head, int data, int position) {
    printf("Inserting %d at position %d\n", data, position);
    struct node* newNode = createNode(data);
    int i = 0;
    while (i < position - 1 && head != NULL) {
        head = head->next;
        i++;
    }
    if (head == NULL) {
        printf("Index out of bounds\n");
        exit(1);
    }
    newNode->next = head->next;
    head->next = newNode;
}

// Function to delete the first node of the linked list
struct node* deleteAtFirst(struct node* head) {
    printf("Deleting node at the beginning\n");
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
void deleteAtEnd(struct node* head) {
    printf("Deleting node at the end\n");
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* prev = NULL;
    while (head->next != NULL) {
        prev = head;
        head = head->next;
    }
    free(head);
    if (prev != NULL) {
        prev->next = NULL;
    }
}

// Function to delete a node at a specified position in the linked list
void deleteAtPosition(struct node* head, int position) {
    printf("Deleting node at position %d\n", position);
    struct node* p = head;
    int i = 0;
    while (p != NULL && i < position - 1) {
        p = p->next;
        i++;
    }
    if (p == NULL || p->next == NULL) {
        printf("Index out of bounds\n");
        return;
    }
    struct node* q = p->next;
    p->next = q->next;
    free(q);
}

// Function to display the linked list
void display(struct node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Example usage:
int main() {
    // Creating an empty linked list
    struct node* head = NULL;

    // Insertion operations
    head = insertAtFirst(head, 1); // Insert at the beginning
    insertAtEnd(head, 3); // Insert at the end
    insertAtPosition(head, 2, 2); // Insert at position 2
    display(head); // Display the linked list

    // Deletion operations
    head = deleteAtFirst(head); // Delete node at the beginning
    deleteAtEnd(head); // Delete node at the end
    display(head); // Display the modified linked list

    return 0;
}
