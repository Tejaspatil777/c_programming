/*Exercise 1
You are given the root of a binary tree. Without using recursion,
implement an algorithm to perform the in order traversal of a
binary tree. Specify the data structure required to simulate the
recursive behavior. Clearly explain your approach, time
complexity*/
#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Stack */
struct Node* stack[100];
int top = -1;

/* Push */
void push(struct Node* node) {
    stack[++top] = node;
}

/* Pop */
struct Node* pop() {
    if (top == -1)
        return NULL;
    return stack[top--];
}

/* Check empty */
int isEmpty() {
    return top == -1;
}

/* Create node */
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Build tree using user input */
struct Node* buildTree() {
    int val;

    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = createNode(val);

    printf("Enter LEFT child of %d\n", val);
    root->left = buildTree();

    printf("Enter RIGHT child of %d\n", val);
    root->right = buildTree();

    return root;
}

/* Inorder traversal (non-recursive) */
void inorder(struct Node* root) {

    struct Node* curr = root;

    while (curr != NULL || !isEmpty()) {

        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

int main() {

    printf("Build Binary Tree\n");
    printf("Use -1 for NULL node\n\n");

    struct Node* root = buildTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    return 0;
}
