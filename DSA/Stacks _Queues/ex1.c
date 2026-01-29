/* Reverse a Stack Using Recursion (No Extra Space):
Given a stack of integers, write a recursive algorithm to reverse
the stack using only the call stack (i.e., no additional data
structures are allowed). Clearly explain the logic and base
conditions used in your approach.*/
#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

/* Push element into stack */
void push(int key)
{
    if (top == 99)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = key;
}

/* Pop element from stack */
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

/* Display stack */
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

/* Insert element at the bottom of stack */
void insertAtBottom(int x)
{
    if (top == -1)
    {
        push(x);
        return;
    }

    int y = pop();
    insertAtBottom(x);
    push(y);
}

/* Reverse the stack using recursion */
void reverseStack()
{
    if (top == -1)
        return;

    int x = pop();
    reverseStack();
    insertAtBottom(x);
}

int main()
{
    int n, key;

    printf("Enter total number of elements in stack: ");
    scanf("%d", &n);

    printf("Enter stack elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        push(key);
    }

    reverseStack();

    display();

    return 0;
}
