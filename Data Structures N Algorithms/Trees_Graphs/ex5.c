/*Exercise 1
Detect and Return the Lowest Common Ancestor (LCA) in a Binary Tree
You are given a binary tree and two distinct nodes p and q. Your task is to
find their Lowest Common Ancestor (LCA) — the lowest node in the tree
that has both p and q as descendants (a node can be a descendant of
itself).
Write an efficient solution to return the LCA node.
Assume that both nodes p and q exist in the tree.
Input:
root: Root node of the binary tree.
p, q: Values of the nodes for which LCA is to be found.
Expected Output:
Return the node (or its value) that is the LCA of p and q Example:
3
/ \
5 1
/ \ / \
6 2 0 8
/ \
7 4
Input: p = 5, q = 1
Output: 3
Input: p = 7, q = 4
Output: 2
Nodes contain unique values.
Tree contains no cycles.
All values are integers in the range [0, 10^4].*/

#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Create node */
struct Node* createNode(int val) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

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

/* Find LCA */
struct Node* findLCA(struct Node* root, int p, int q) {

    if (root == NULL)
        return NULL;

    /* If match found */
    if (root->data == p || root->data == q)
        return root;

    struct Node* left =
        findLCA(root->left, p, q);

    struct Node* right =
        findLCA(root->right, p, q);

    /* If both sides return non-null */
    if (left && right)
        return root;

    /* Else return non-null side */
    return (left != NULL) ? left : right;
}

int main() {

    printf("Build Binary Tree\n");
    printf("Use -1 for NULL node\n\n");

    struct Node* root = buildTree();

    int p, q;
    printf("\nEnter value of p: ");
    scanf("%d", &p);

    printf("Enter value of q: ");
    scanf("%d", &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("\nLCA of %d and %d is: %d\n",
               p, q, lca->data);

    return 0;
}
