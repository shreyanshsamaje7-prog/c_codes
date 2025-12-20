#include <stdio.h>

#define MAX 50

int n;
int G[MAX][MAX];
int visited[MAX];

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while(front <= rear) {
        int v = queue[front++];   // Dequeue
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(G[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;  // Enqueue
            }
        }
    }
    printf("\n");
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}