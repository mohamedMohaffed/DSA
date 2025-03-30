#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    
    // If the queue is empty, both front and rear will point to the new node
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Add the new node at the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued to queue\n", value);
}

// Function to dequeue (remove) an element from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
    } else {
        struct Node* temp = queue->front;
        printf("Dequeued: %d\n", temp->data);
        queue->front = queue->front->next;
        free(temp);

        // If the queue becomes empty after dequeue, set rear to NULL
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
    }
}

// Function to peek at the front element of the queue
void peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Front Element: %d\n", queue->front->data);
    }
}

// Function to display all elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = queue->front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the queue operations
int main() {
    struct Queue queue;
    initQueue(&queue);

    // Directly perform operations
    enqueue(&queue, 10);    // Enqueue 10
    enqueue(&queue, 20);    // Enqueue 20
    enqueue(&queue, 30);    // Enqueue 30
    display(&queue);        // Display the queue

    dequeue(&queue);        // Dequeue the front element
    display(&queue);        // Display the queue after dequeue

    peek(&queue);           // Peek at the front element

    dequeue(&queue);        // Dequeue another element
    display(&queue);        // Display the queue after dequeue

    return 0;
}
