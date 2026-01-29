/*Exercise 1
Diameter of a Binary Tree
Given the root of a binary tree, write an algorithm to compute its
diameter.
The diameter is defined as the length of the longest path between any
two nodes in the tree (number of edges).
• Explain the recursive approach clearly.
• Optimize the solution to avoid recomputing heights.*/
#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Create node */
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Utility max */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Height + Diameter (optimized) */
int height(struct Node* root, int *diameter) {

    if (root == NULL)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    if (lh + rh > *diameter)
        *diameter = lh + rh;

    return max(lh, rh) + 1;
}

/* Get diameter */
int getDiameter(struct Node* root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}

/* Build tree using user input (recursive) */
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

int main() {

    printf("Build Binary Tree\n");
    printf("Use -1 for NULL\n\n");

    struct Node* root = buildTree();

    printf("\nDiameter of tree: %d\n", getDiameter(root));

    return 0;
}
