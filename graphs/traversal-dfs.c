#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int adj[MAX][MAX] = {0};       
bool visited[MAX] = {false};    

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < MAX; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 6);

    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0
