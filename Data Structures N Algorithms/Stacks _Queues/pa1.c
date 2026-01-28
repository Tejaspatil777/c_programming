/*Practice Assignment I
Task Management System with Stacks and Queues
Problem Description
A task management application needs a system to manage tasks using
stacks and queues. This case study outlines a structured approach for
developing a simple Task Management System using these data
structures.
This Beginner to Intermediate case study helps you apply your knowledge and skills
of Stacks ad Queues to solve the problems of a real-life scenario.
1
MODULE | DATA STRUCTURE AND ANAYSIS OF ALGORITHM
This material is owned by Tata Consultancy Services Limited. Unauthorized duplication,
reproduction, downloading, or screen capturing is strictly forbidden and may result in legal
action, unless you obtain TCS's written permission. Using our Services does not give you
ownership of any intellectual property rights in our Services or the content you access.
2
Tasks
1. Stack Management
Create a class to represent a stack of tasks. Each stack should
support the following operations:
• Push (add a task to the stack)
• Pop (remove the most recent task from the stack)
• Peek (view the most recent task in the stack)
• IsEmpty (check if the stack is empty)
2. Queue Management
Create a class to represent a queue of tasks. Each queue should
support the following operations:
• Enqueue (add a task to the queue)
• Dequeue (remove the oldest task from the queue)
• Front (view the oldest task in the queue)
• IsEmpty (check if the queue is empty)*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ========== TASK STRUCTURE ========== */
struct Task {
    char name[50];
};

/* ========== STACK IMPLEMENTATION ========== */
#define MAX 10
struct Task stack[MAX];
int top = -1;

/* Push task into stack */
void push(char taskName[]) {
    if (top == MAX - 1) {
        printf("Stack is full! Cannot add more tasks.\n");
        return;
    }
    top++;
    strcpy(stack[top].name, taskName);
    printf("Task added to STACK: %s\n", taskName);
}

/* Pop task from stack */
void pop() {
    if (top == -1) {
        printf("Stack is empty! Nothing to remove.\n");
        return;
    }
    printf("Task removed from STACK: %s\n", stack[top].name);
    top--;
}

/* Peek stack */
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Latest task in STACK: %s\n", stack[top].name);
}

/* Check stack empty */
int isStackEmpty() {
    return top == -1;
}

/* ========== QUEUE IMPLEMENTATION ========== */
struct Task queue[MAX];
int front = -1, rear = -1;

/* Enqueue task */
void enqueue(char taskName[]) {
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot add more tasks.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear].name, taskName);
    printf("Task added to QUEUE: %s\n", taskName);
}

/* Dequeue task */
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Nothing to remove.\n");
        return;
    }

    printf("Task removed from QUEUE: %s\n", queue[front].name);
    front++;
}

/* Front element */
void showFront() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Oldest task in QUEUE: %s\n", queue[front].name);
}

/* Check queue empty */
int isQueueEmpty() {
    return (front == -1 || front > rear);
}

/* ========== MAIN MENU ========== */
int main() {

    int choice;
    char taskName[50];

    while (1) {
        printf("\n--- TASK MANAGEMENT SYSTEM ---\n");
        printf("1. Add Task to Stack\n");
        printf("2. Remove Task from Stack\n");
        printf("3. View Latest Stack Task\n");
        printf("4. Add Task to Queue\n");
        printf("5. Remove Task from Queue\n");
        printf("6. View Oldest Queue Task\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter task name: ");
            scanf("%s", taskName);
            push(taskName);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            printf("Enter task name: ");
            scanf("%s", taskName);
            enqueue(taskName);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            showFront();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
