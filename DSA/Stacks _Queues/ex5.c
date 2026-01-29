/*Interleave First Half of Queue with Second Half
You are given a queue of integers with an even number of elements. Your
task is to write a program that interleaves the first half of the queue with
the second half using only one additional stack and no other data
structures.
Example:
Input Queue:
[1, 2, 3, 4, 5, 6]
Output Queue (after interleaving):
[1, 4, 2, 5, 3, 6].*/
#include <stdio.h>
#include <stdlib.h>


struct QNode {
    int data;
    struct QNode* next;
};


struct SNode {
    int data;
    struct SNode* next;
};


void enqueue(struct QNode** front, struct QNode** rear, int x) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->data = x;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct QNode** front, struct QNode** rear) {
    struct QNode* temp = *front;
    int val = temp->data;

    *front = temp->next;
    if (*front == NULL)
        *rear = NULL;

    free(temp);
    return val;
}

void push(struct SNode** top, int x) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct SNode** top) {
    struct SNode* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int isStackEmpty(struct SNode* top) {
    return top == NULL;
}


int getSize(struct QNode* front) {
    int count = 0;
    while (front != NULL) {
        count++;
        front = front->next;
    }
    return count;
}

void interleaveQueue(struct QNode** front, struct QNode** rear) {
    int n = getSize(*front);

    if (n % 2 != 0) {
        printf("Queue must have even number of elements\n");
        return;
    }

    int half = n / 2;
    struct SNode* stack = NULL;

    
    for (int i = 0; i < half; i++)
        push(&stack, dequeue(front, rear));

   
    while (!isStackEmpty(stack))
        enqueue(front, rear, pop(&stack));

    for (int i = 0; i < half; i++)
        enqueue(front, rear, dequeue(front, rear));

  
    for (int i = 0; i < half; i++)
        push(&stack, dequeue(front, rear));

   
    while (!isStackEmpty(stack)) {
        enqueue(front, rear, pop(&stack));
        enqueue(front, rear, dequeue(front, rear));
    }
}

void display(struct QNode* front) {
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}


int main() {
    struct QNode *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 6);

    printf("Original Queue: ");
    display(front);

    interleaveQueue(&front, &rear);

    printf("Interleaved Queue: ");
    display(front);

    return 0;
}