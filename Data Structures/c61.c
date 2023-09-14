#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to insert a new node between two nodes
void insertBetween(struct Node* prevNode, int value) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Display the linked list before operations
    printf("Linked List before operations:\n");
    printList(head);

    // a. Insertion of 5 at the beginning
    insertAtBeginning(&head, 5);
     printf("\n Linked List after (1) operations:\n");
    printList(head);

    // b. Insertion of 60 at the end
    insertAtEnd(&head, 60);
     printf("\n Linked List after(2) operations:\n");
    printList(head);

    // c. Insertion of 45 between 40 and 50
    struct Node* prevNode = head->next->next->next; // Points to node with value 40
    insertBetween(prevNode, 45);

    // Display the linked list after operations
    printf("\nLinked List after all operations:\n");
    printList(head);

    return 0;
}