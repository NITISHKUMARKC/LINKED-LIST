// C program to create and display a linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node*createLinkedList(){
    struct Node*head,*newnode,*temp;
    int choice;
    head = NULL;
    do {
        // Allocate memory for new node
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }
        // Input data for the new node
        printf("Enter data for the new node: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL) {
            // If the list is empty, make the new node the head
            head = newnode;
        } else {
            // Otherwise, traverse to the end of the list and add the new node
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        // Ask user if they want to continue
        printf("Do you want to add another node? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice != 0);
    return head;
}
// Function to display the linked list
void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    // Create the linked list
    struct Node* head = createLinkedList();
    // Display the linked list
    displayLinkedList(head);
    return 0;
}