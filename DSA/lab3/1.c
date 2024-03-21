#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int capacity = MAX_SIZE;
int *array;

// Function to initialize a queue
void createQueue()
{
    array = (int *)malloc(capacity * sizeof(int));
}

// Function to check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Function to check if the queue is full
int isFull()
{
    return (rear + 1) % capacity == front;
}

// Function to enqueue an element into the queue
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    if (isEmpty())
        front = 0;

    rear = (rear + 1) % capacity;
    array[rear] = item;
    printf("Enqueued: %d\n", item);
}

// Function to dequeue an element from the queue
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int item = array[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % capacity;

    return item;
}

// Function to display the elements in the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    do
    {
        printf("%d ", array[i]);
        i = (i + 1) % capacity;
    } while (i != (rear + 1) % capacity);
    printf("\n");
}

// Main function to demonstrate the usage of queues
int main()
{
    // Create a queue
    createQueue();

    // Enqueue some elements
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Display and dequeue elements from the queue
    display();
    printf("Dequeued: %d\n", dequeue());
    display();

    // Enqueue more elements
    enqueue(40);
    enqueue(50);
    enqueue(60);

    // Display and dequeue elements from the queue
    display();
    printf("Dequeued: %d\n", dequeue());
    display();

    // Enqueue more elements to demonstrate circular behavior
    enqueue(70);
    enqueue(80);

    // Display the circular queue
    display();

    // Free allocated memory
    free(array);

    return 0;
}
