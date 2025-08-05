// Implementation of Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert an element into the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue\n", value);
}

// Function to delete an element from the queue
void dequeue() {
    struct Node* temp;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    printf("%d dequeued from the queue\n", temp->data);
    free(temp);
}

// Function to display the elements of the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
