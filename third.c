// Deletation at the beginning of the linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to delete the first node of the linked list
struct Node* deleteAtBeginning(struct Node* head) {
struct Node *temp;
   int choice;
   do{
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return head;
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
        }
        return head;
    printf("Do you want to delete another node? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice == 1); // Repeat until user chooses to stop
    return head;
    }
// Function to display the linked list
struct Node* display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The linked list is empty.\n");
        return head;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return head;
}
int main() {
    // Create the linked list
    struct Node* head = NULL;
    head = deleteAtBeginning(head);
    // Display the linked list
    display(head);
    return 0;
}
