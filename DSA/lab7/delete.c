#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to delete the first node of the linked list
struct node* deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Function to delete a node at a specified index in the linked list
void deleteMiddle(struct node* head, int index) {
    struct node* p = head;
    int i = 0;
    while (p != NULL && i < index - 1) {
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

// Function to delete the last node of the linked list
void deleteEnd(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* p = head;
    struct node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

// Function to display the linked list
void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Example usage:
int main() {
    // Creating a linked list
    struct node* head = NULL;
    head = insertAtFirst(head, 1); // Insert at the beginning
    insertAtEnd(head, 3); // Insert at the end
    insertAtMiddle(head, 2, 2); // Insert at index 2
    // Now the linked list should be: 1 -> 2 -> 3
    display(head); // Display the linked list
    
    head = deleteFirst(head); // Delete the first node
    deleteMiddle(head, 1); // Delete node at index 1
    deleteEnd(head); // Delete the last node
    // Now the linked list should be: 2
    display(head); // Display the modified linked list
    
    return 0;
}
