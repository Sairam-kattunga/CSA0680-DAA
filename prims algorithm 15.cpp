#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX], visited[MAX], dist[MAX], parent[MAX];
int numVertices, numEdges;

int findMinDistVertex() {
    int minDist = INF, minVertex = -1;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void prim(int start) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        int u = findMinDistVertex();
        visited[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (parent[i] != -1) {
            printf("%d - %d : %d\n", parent[i], i, dist[i]);
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges and their weights:\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Minimum Spanning Tree:\n");
    prim(startVertex);

    return 0;
}

