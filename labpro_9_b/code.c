#include <stdio.h>

#define MAX 50

int n;
int G[MAX][MAX];
int visited[MAX];

void DFS(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(G[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(0);   // start DFS from vertex 0

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if(connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");

    return 0;
}
