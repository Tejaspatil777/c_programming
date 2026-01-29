/*Palindrome Check in a Queue with Minimal Space
You are given a queue of integers. Your task is to design an efficient
algorithm to check whether the sequence of elements forms a
palindrome, i.e., the sequence reads the same forward and
backward.
• Use no extra space or only minimal additional memory (constant
space).
• You are not allowed to modify the original queue permanently
(you may temporarily alter it but must restore it to the original
state).
• Include edge cases, constraints, and any trade-offs your solution
introduces in terms of time or space complexity.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void enqueue(struct Node** front, struct Node** rear, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}


struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct Node* front) {
    if (front == NULL || front->next == NULL)
        return 1;

    struct Node *slow = front, *fast = front;

    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    struct Node* secondHalf = reverse(slow->next);
    struct Node* copySecond = secondHalf;

    
    struct Node* firstHalf = front;
    int isPalin = 1;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            isPalin = 0;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

   
    slow->next = reverse(copySecond);

    return isPalin;
}


void display(struct Node* front) {
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}


int main() {
    struct Node *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 1);

    printf("Queue: ");
    display(front);

    if (isPalindrome(front))
        printf("Queue is a palindrome\n");
    else
        printf("Queue is NOT a palindrome\n");

    printf("Queue after check (restored): ");
    display(front);

    return 0;
}