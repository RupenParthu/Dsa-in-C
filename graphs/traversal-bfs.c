#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int adj[MAX][MAX] = {0};        // Adjacency Matrix
bool visited[MAX] = {false};      // Visited Array

// Queue Implementation
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    if (rear < MAX)
        queue[rear++] = x;
}

int dequeue() {
    if (front < rear)
        return queue[front++];
    return -1; // Return -1 if queue is empty
}

bool isEmpty() {
    return (front == rear);
}

// Add undirected edge
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// BFS function
void BFS(int start) {
    visited[start] = true;
    enqueue(start);

    while (!isEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);

        // Check and enqueue neighbors
        for (int i = 0; i < MAX; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

// Main function
int main() {
    // Build a simple undirected graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 6);

    printf("BFS Traversal: ");
    BFS(0);
    printf("\n");

    return 0;
}
