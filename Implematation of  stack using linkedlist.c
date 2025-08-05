#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Initialize top pointer
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    struct Node* temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
     temp= top;
    printf("%d popped from the stack\n", top->data);
    top = top->next;
    free(temp);
}

// Function to peek at the top element of the stack
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

// Function to display the elements of the stack
void display() {
    struct Node* temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Stack elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    push(10);
    push(20);
    push(30);
    display();   // Optional: to see the stack after pushes
    pop();
    display();   // Optional: to see the stack after pop
    return 0;
}

