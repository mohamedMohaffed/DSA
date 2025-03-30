#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself (circular)
    return newNode;
}

// Insert at the end of the circular linked list
void insertAt(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Delete a node from a given position
void deleteAt(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {  // Delete head node
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        return;
    }

    // Traverse to the node just before the position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == *head) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Update a node's data at a given position
void updateAt(struct Node* head, int position, int newData) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == head) {
        printf("Position out of range.\n");
        return;
    }

    temp->data = newData;
}

// Display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAt(&head, 10);
    insertAt(&head, 20);
    insertAt(&head, 30);
    insertAt(&head, 40);

    printf("Circular Linked List: ");
    display(head);

    updateAt(head, 2, 25);
    printf("After updating position 2 to 25: ");
    display(head);

    deleteAt(&head, 3);
    printf("After deleting position 3: ");
    display(head);

    return 0;
}
