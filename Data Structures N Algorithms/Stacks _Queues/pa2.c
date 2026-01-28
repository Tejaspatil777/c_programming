/*Practice Assignment II
Ticket Booking System with Stacks and Queues
Problem Description
A ticket booking application needs a system to manage ticket bookings
using stacks and queues. This case study outlines a structured approach
for developing a simple Ticket Booking System using these data
structures.
This Intermediate to Advanced case study helps you apply your knowledge and skills
of Stacks and Queues to solve the problems of a real-life scenario.
1
MODULE | DATA STRUCTURE AND ANALYSIS OF ALGORITHM
This material is owned by Tata Consultancy Services Limited. Unauthorized duplication,
reproduction, downloading, or screen capturing is strictly forbidden and may result in legal
action, unless you obtain TCS's written permission. Using our Services does not give you
ownership of any intellectual property rights in our Services or the content you access.
2
Tasks
1. Stack Management
Create a class to represent a stack of ticket bookings. Each stack
should support the following operations:
• Push (add a booking to the stack)
• Pop (remove the most recent booking from the stack)
• Peek (view the most recent booking in the stack)
• IsEmpty (check if the stack is empty)
2. Queue Management
Create a class to represent a queue of ticket bookings. Each queue
should support the following operations:
• Enqueue (add a booking to the queue)
• Dequeue (remove the oldest booking from the queue)
• Front (view the oldest booking in the queue)
• IsEmpty (check if the queue is empty)
MODULE | DATA STRUCTURE AND ANALYSIS OF ALGORITHM
Stacks and Queues
Unauthorized duplication, reproduction, downloading, or screen capturing is strictly
forbidden and may result in legal action.
3
Hints
ü Use a stack to manage ticket bookings for last-in-first-out (LIFO)
order.
ü Use a queue to manage ticket bookings for first-in-first-out (FIFO)
order.
ü Implement methods to push, pop, peek, and check if the stack is
empty.
ü Implement methods to enqueue, dequeue, view the front element,
and check if the queue is empty.
ü Test the system by adding bookings, removing bookings, viewing the
most recent and oldest bookings, and checking if the stack and queue
are empty*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

/* ===== Ticket Structure ===== */
struct Ticket {
    char name[50];   // Passenger name
};

/* ===== STACK (Recent Bookings - LIFO) ===== */
struct Ticket stack[MAX];
int top = -1;

/* Add booking to stack */
void push(char name[]) {
    if (top == MAX - 1) {
        printf("Stack is full! Cannot add booking.\n");
        return;
    }
    top++;
    strcpy(stack[top].name, name);
    printf("Booking added to STACK: %s\n", name);
}

/* Remove recent booking */
void pop() {
    if (top == -1) {
        printf("Stack is empty! No booking to remove.\n");
        return;
    }
    printf("Recent booking removed: %s\n", stack[top].name);
    top--;
}

/* View recent booking */
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Most recent booking: %s\n", stack[top].name);
}

/* Check stack empty */
int isStackEmpty() {
    return top == -1;
}

/* ===== QUEUE (Pending Bookings - FIFO) ===== */
struct Ticket queue[MAX];
int front = -1, rear = -1;

/* Add booking to queue */
void enqueue(char name[]) {
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot add booking.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear].name, name);
    printf("Booking added to QUEUE: %s\n", name);
}

/* Remove oldest booking */
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! No booking to remove.\n");
        return;
    }

    printf("Oldest booking removed: %s\n", queue[front].name);
    front++;
}

/* View oldest booking */
void showFront() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Oldest booking: %s\n", queue[front].name);
}

/* Check queue empty */
int isQueueEmpty() {
    return (front == -1 || front > rear);
}

/* ===== MAIN MENU ===== */
int main() {

    int choice;
    char name[50];

    while (1) {
        printf("\n--- TICKET BOOKING SYSTEM ---\n");
        printf("1. Add Booking (Stack)\n");
        printf("2. Cancel Recent Booking (Stack)\n");
        printf("3. View Recent Booking\n");
        printf("4. Add Booking (Queue)\n");
        printf("5. Process Oldest Booking (Queue)\n");
        printf("6. View Oldest Booking\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter passenger name: ");
            scanf("%s", name);
            push(name);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            printf("Enter passenger name: ");
            scanf("%s", name);
            enqueue(name);
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
