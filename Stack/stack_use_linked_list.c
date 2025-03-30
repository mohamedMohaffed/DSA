#include <stdio.h>
#include <stdlib.h>

// Define structure for stack node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Initially, the stack is empty

// Function to push an element onto the stack
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack\n", x);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }

    struct Node* temp = top;
    top = top->next; // Move top to the next node
    printf("Popped: %d\n", temp->data);

    free(temp); // Free the memory of the popped node
}

// Function to peek at the top element of the stack
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top Element: %d\n", top->data);
}

// Function to display all elements of the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    // Directly perform operations
    push(10);    // Push 10
    push(20);    // Push 20
    push(30);    // Push 30
    display();   // Display the stack

    pop();       // Pop the top element
    display();   // Display the stack after pop

    peek();      // Peek the top element

    pop();       // Pop another element
    display();   // Display the stack after pop

    return 0;
}
