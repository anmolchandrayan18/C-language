#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Queue operations
void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;

    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;

    int val = queue[front++];
    return val;
}

// BFS function
void BFS(int start, int vertices) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix and visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1; // undirected graph
    }

    // BFS traversal
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    BFS(start, vertices);

    printf("\n");

    return 0;
}
