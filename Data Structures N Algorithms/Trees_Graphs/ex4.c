#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* DFS function */
int isCyclicUtil(int graph[MAX][MAX], int node,
                 int visited[], int recStack[], int V) {

    visited[node] = 1;     // mark visited
    recStack[node] = 1;   // add to recursion stack

    for (int i = 0; i < V; i++) {

        if (graph[node][i]) {

            /* If not visited -> DFS */
            if (!visited[i]) {
                if (isCyclicUtil(graph, i, visited, recStack, V))
                    return 1;
            }

            /* If already in recursion stack -> cycle */
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0;   // remove from recursion stack
    return 0;
}

/* Main cycle check */
int isCyclic(int graph[MAX][MAX], int V) {

    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, recStack, V))
                return 1;
        }
    }
    return 0;
}

int main() {

    int V, E;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;   // directed edge u -> v
    }

    if (isCyclic(graph, V))
        printf("\nCycle detected in graph\n");
    else
        printf("\nNo cycle in graph\n");

    return 0;
}
