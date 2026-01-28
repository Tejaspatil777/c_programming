/*Practice Assignment II
Graph Implementation with Dijkstra's Algorithm
Problem Description
A software application needs a system to manage a graph and find the
shortest path using Dijkstra's algorithm. This case study outlines a
structured approach for developing a simple Graph Implementation with
Dijkstra's Algorithm.
This Intermediate to Advanced case study helps you apply your knowledge and skills
of Trees and Graphs to solve the problems of a real-life scenario.
1
MODULE | DATA STRUCTURE AND ANALYSIS OF ALGORITHM
This material is owned by Tata Consultancy Services Limited. Unauthorized duplication,
reproduction, downloading, or screen capturing is strictly forbidden and may result in legal
action, unless you obtain TCS's written permission. Using our Services does not give you
ownership of any intellectual property rights in our Services or the content you access.
2
Tasks
1. Graph Management
Create a class to represent a graph. Each graph should support the
following operations:
• Add Vertex (add a vertex to the graph)
• Add Edge (add an edge between two vertices with a weight)
• Display (display the graph)
2. Shortest Path Calculation
Implement Dijkstra's algorithm to find the shortest path from a source
vertex to all other vertices.
Hints
ü Use a class to represent the graph.
ü Implement methods to add vertices and edges, and display the
graph.
ü Implement Dijkstra's algorithm to find the shortest path.
ü Test the system by adding vertices and edges, displaying the graph,
and finding the shortest path using Dijkstra's algorithm.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

int graph[MAX][MAX];
int vertices = 0;

/* ---------- Add Vertex ---------- */
void addVertex() {

    if(vertices >= MAX){
        printf("❌ Vertex limit reached (Max %d)\n", MAX);
        return;
    }

    vertices++;
    printf("✅ Vertex %d added successfully\n", vertices-1);
}

/* ---------- Add Edge ---------- */
void addEdge(int u, int v, int w){

    if(u < 0 || v < 0 || u >= vertices || v >= vertices){
        printf("❌ Invalid vertex number!\n");
        return;
    }

    if(w <= 0){
        printf("❌ Weight must be positive!\n");
        return;
    }

    graph[u][v] = w;
    graph[v][u] = w;   // Undirected

    printf("✅ Edge added safely between %d and %d\n", u, v);
}

/* ---------- Display ---------- */
void display(){

    if(vertices == 0){
        printf("⚠ No vertices added yet!\n");
        return;
    }

    printf("\nAdjacency Matrix (Weights):\n   ");
    for(int i=0;i<vertices;i++)
        printf("%d ",i);

    printf("\n");

    for(int i=0;i<vertices;i++){
        printf("%d: ",i);
        for(int j=0;j<vertices;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
}

/* ---------- Dijkstra ---------- */
void dijkstra(int src){

    if(src < 0 || src >= vertices){
        printf("❌ Invalid source vertex!\n");
        return;
    }

    int dist[MAX];
    int visited[MAX] = {0};

    for(int i=0;i<vertices;i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(int count=0; count<vertices-1; count++){

        int min = INT_MAX, u = -1;

        /* find min distance vertex */
        for(int i=0;i<vertices;i++)
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }

        if(u == -1) break;   // disconnected graph safety

        visited[u] = 1;

        /* relax edges */
        for(int v=0; v<vertices; v++){

            if(!visited[v] && graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]){

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\n📌 Shortest distances from %d:\n", src);
    for(int i=0;i<vertices;i++){
        if(dist[i] == INT_MAX)
            printf("To %d = INF\n", i);
        else
            printf("To %d = %d\n", i, dist[i]);
    }
}

/* ---------- Main ---------- */
int main(){

    int ch,u,v,w,src;

    /* initialize graph */
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            graph[i][j] = 0;

    while(1){

        printf("\n======= DIJKSTRA MENU =======\n");
        printf("1. Add Vertex\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. Find Shortest Path\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        if(scanf("%d",&ch)!=1){
            printf("❌ Invalid input!\n");
            exit(0);
        }

        switch(ch){

        case 1:
            addVertex();
            break;

        case 2:
            printf("Enter u v weight: ");
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Enter source vertex: ");
            scanf("%d",&src);
            dijkstra(src);
            break;

        case 5:
            printf("Program closed safely 👍\n");
            exit(0);

        default:
            printf("❌ Invalid menu option!\n");
        }
    }

    return 0;
}
