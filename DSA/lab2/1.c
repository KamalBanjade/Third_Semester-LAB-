#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Define the maximum size of the stack

struct Stack {
    int items[MAX_SIZE];
    int top; // Variable to keep track of the top element
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1; // Initialize the top as -1 to indicate an empty stack
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1; // If top is -1, the stack is empty
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1; // If top is at the maximum size, the stack is full
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element.\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
    printf("%d pushed to the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1; // Return a sentinel value (-1 in this case) to indicate an error or an empty stack
    }
    int popped = stack->items[stack->top];
    stack->top--;
    return popped;
}

// Function to peek the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek.\n");
        return -1; // Return a sentinel value (-1 in this case) to indicate an error or an empty stack
    }
    return stack->items[stack->top];
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Top element after pop: %d\n", peek(&stack));

    return 0;
}
