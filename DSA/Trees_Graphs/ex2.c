/*Exercise 2
You are given an unweighted undirected graph represented as an
adjacency list and two nodes start and end.
Write a program using Breadth-First Search (BFS) to find the shortest path
(minimum number of edges) between start and end.
• Track the path, not just the distance.
• Output the actual sequence of nodes in the shortest path from start
to end.
• If no path exists, return an empty list.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* Queue */
int queue[MAX];
int front = 0, rear = -1;

/* Enqueue */
void enqueue(int x) {
    queue[++rear] = x;
}

/* Dequeue */
int dequeue() {
    return queue[front++];
}

/* Check empty */
int isEmpty() {
    return front > rear;
}

/* BFS shortest path */
void bfs(int graph[MAX][MAX], int n, int start, int end) {

    int visited[MAX] = {0};
    int parent[MAX];

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {

        int curr = dequeue();

        for (int i = 0; i < n; i++) {

            if (graph[curr][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                parent[i] = curr;
            }
        }
    }

    /* No path */
    if (!visited[end]) {
        printf("\nNo path exists\n");
        return;
    }

    /* Print path */
    int path[MAX], count = 0;
    int temp = end;

    while (temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }

    printf("\nShortest Path: ");
    for (int i = count - 1; i >= 0; i--)
        printf("%d ", path[i]);

    printf("\nDistance (edges): %d\n", count - 1);
}

int main() {

    int n, e;
    int graph[MAX][MAX] = {0};
    int start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        /* Undirected graph */
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter end node: ");
    scanf("%d", &end);

    bfs(graph, n, start, end);

    return 0;
}
