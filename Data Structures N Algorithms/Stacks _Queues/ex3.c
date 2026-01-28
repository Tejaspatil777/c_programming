/*Stack Sorting Using Another Stack
You are given two stacks, Stack A and Stack B.
• Stack A contains a set of unsorted integers.
• Stack B is initially empty and can be used as a helper stack.
• Your task is to sort the elements in Stack A in ascending order using
only Stack B and basic stack operations (push, pop, peek, isEmpty).
Mention the time complexity and space usage. You are not allowed to
use arrays, recursion, or additional data structures.*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack* next;
};

void push(struct Stack** top, int x) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}


int pop(struct Stack** top) {
    struct Stack* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}


int peek(struct Stack* top) {
    return top->data;
}

int isEmpty(struct Stack* top) {
    return top == NULL;
}


void sortStack(struct Stack** A) {
    struct Stack* B = NULL;

    while (!isEmpty(*A)) {
        int temp = pop(A);

        while (!isEmpty(B) && peek(B) > temp) {
            push(A, pop(&B));
        }

        push(&B, temp);
    }


    while (!isEmpty(B)) {
        push(A, pop(&B));
    }
}

void display(struct Stack* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Stack* A = NULL;

    push(&A, 3);
    push(&A, 1);
    push(&A, 4);
    push(&A, 2);

    printf("Original Stack A (Top to Bottom): ");
    display(A);

    sortStack(&A);

    printf("Sorted Stack A (Top to Bottom): ");
    display(A);

    return 0;
}