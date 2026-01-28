/*Practice Assignment I
Graph Implementation with BFS and DFS
Problem Description
A software application needs a system to manage a graph and perform
breadth-first search (BFS) and depth-first search (DFS). This case study
outlines a structured approach for developing a simple Graph
Implementation with BFS and DFS.
This Beginner to Intermediate case study helps you apply your knowledge and skills
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
• Create a class to represent a graph. Each graph should support the
following operations:
• Add Vertex (add a vertex to the graph)
• Add Edge (add an edge between two vertices)
• Display (display the graph)
2. Graph Traversal
• Implement methods for graph traversal:
• Breadth-First Search (BFS)
• Depth-First Search (DFS)
Hints
ü Use a class to represent the graph.
ü Implement methods to add vertices and edges, and display the
graph.
ü Implement methods for BFS and DFS traversal.
ü Test the system by adding vertices and edges, displaying the graph,
and performing BFS and DFS traversal.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* Graph adjacency matrix */
int graph[MAX][MAX] = {0};
int vertices = 0;

/* ================= ADD VERTEX ================= */
/*
User input:
Menu me option 1 select karo
Har baar ek new vertex add hoga
Vertex numbering automatic hogi
0,1,2,3... 
*/
void addVertex() {

    if(vertices == MAX){
        printf("Maximum vertex limit reached!\n");
        return;
    }

    vertices++;
    printf("Vertex %d added successfully\n", vertices-1);
}

/* ================= ADD EDGE ================= */
/*
User input format:
Enter u v

Example:
0 1
matlab edge between vertex 0 and 1
*/
void addEdge(int u,int v){

    if(u>=vertices || v>=vertices){
        printf("Invalid vertices!\n");
        return;
    }

    /* Undirected graph */
    graph[u][v]=1;
    graph[v][u]=1;

    printf("Edge added between %d and %d\n",u,v);
}

/* ================= DISPLAY ================= */
/*
Graph ko matrix form me show karega
*/
void display(){

    printf("\nAdjacency Matrix:\n   ");

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

/* ================= BFS ================= */
/*
User input:
Start vertex enter karo

Example:
0
BFS 0 se start hogi
*/
void bfs(int start){

    if(start>=vertices){
        printf("Invalid start vertex\n");
        return;
    }

    int visited[MAX]={0};
    int q[MAX],f=0,r=-1;

    q[++r]=start;
    visited[start]=1;

    printf("BFS Traversal: ");

    while(f<=r){

        int curr=q[f++];
        printf("%d ",curr);

        for(int i=0;i<vertices;i++){
            if(graph[curr][i] && !visited[i]){
                visited[i]=1;
                q[++r]=i;
            }
        }
    }
    printf("\n");
}

/* ================= DFS ================= */
/*
User input:
Start vertex enter karo

Example:
0
DFS 0 se start hogi
*/
void dfsUtil(int node,int visited[]){

    visited[node]=1;
    printf("%d ",node);

    for(int i=0;i<vertices;i++)
        if(graph[node][i] && !visited[i])
            dfsUtil(i,visited);
}

void dfs(int start){

    if(start>=vertices){
        printf("Invalid start vertex\n");
        return;
    }

    int visited[MAX]={0};

    printf("DFS Traversal: ");
    dfsUtil(start,visited);
    printf("\n");
}

/* ================= MAIN ================= */
/*
INPUT FLOW:

1) Option 1 -> vertex add karo
2) Option 2 -> edges add karo (u v)
3) Option 3 -> display graph
4) Option 4 -> BFS (start vertex do)
5) Option 5 -> DFS (start vertex do)
6) Option 6 -> exit

Example input sequence:

1
1
1
2
0 1
2
1 2
3
4
0
5
0
6
*/

int main(){

    int ch,u,v,s;

    while(1){

        printf("\n--- GRAPH MENU ---\n");
        printf("1. Add Vertex\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. BFS Traversal\n");
        printf("5. DFS Traversal\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){

        case 1:
            addVertex();
            break;

        case 2:
            printf("Enter u v: ");
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Enter start vertex: ");
            scanf("%d",&s);
            bfs(s);
            break;

        case 5:
            printf("Enter start vertex: ");
            scanf("%d",&s);
            dfs(s);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
