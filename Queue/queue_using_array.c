#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    if (rear == MAX - 1) {
        return 1;  // Queue is full
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;  // Queue is empty
    }
    return 0;
}

// Function to enqueue (insert) an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;  // Set front to 0 when the first element is inserted
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front Element: %d\n", queue[front]);
    }
}

// Function to display all elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to test the queue operations
int main() {
    // Directly perform operations
    enqueue(10);    // Enqueue 10
    enqueue(20);    // Enqueue 20
    enqueue(30);    // Enqueue 30
    display();      // Display the queue

    dequeue();      // Dequeue the front element
    display();      // Display the queue after dequeue

    peek();         // Peek at the front element

    dequeue();      // Dequeue another element
    display();      // Display the queue after dequeue

    return 0;
}
