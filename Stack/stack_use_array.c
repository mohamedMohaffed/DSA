#include <stdio.h>
#include <stdlib.h>

#define N 50

int stack[N];
int top = -1;

void push(int x)
{
    if (top == N - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed to Stack\n", x);
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("Popped: %d\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top Element: %d\n", stack[top]);
    }
}

void display()
{
    printf("Displaying Stack....\n");
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    // Directly enter commands in the main function
    push(1);    // Push 1 to stack
    push(2);    // Push 2 to stack
    push(3);    // Push 3 to stack
    display();  // Display stack
    
    pop();      // Pop an element from stack
    display();  // Display stack after pop
    
    push(4);    // Push 4 to stack
    peek();     // Show the top element
    
    pop();      // Pop another element
    display();  // Display stack after pop

    return 0;
}
