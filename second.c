// Insertation at the beginning
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node *head){
    struct Node *newnode;
    int choice;
    do {
        // Allocate Memory for new node
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }
        // Input data for the new node
        printf("Enter data for new node: ");
        scanf("%d", &newnode->data);
        // Point the new node's next to the current head
        newnode->next = head;
        head = newnode; // Update head to point to the new node

        // Ask user if they want to continue
        printf("Do you want to add another node? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice==1);// Repeat until user chooses to stop
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
    // Create the linked list by inserting nodes at the beginning
    struct Node* head = NULL;
    head = insertAtBeginning(head);
    // Display the linked list
    displayLinkedList(head);
    return 0;
}

