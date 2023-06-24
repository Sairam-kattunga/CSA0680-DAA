#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 1000
typedef struct 
{
    int u, v, weight;
} 
Edge;
typedef struct 
{
    int parent, rank;
} 
Subset;
int num_vertices, num_edges;
Edge edges[MAX_EDGES];
Subset subsets[MAX_VERTICES];

int find(int x) 
{
    if (subsets[x].parent != x) 
	{
        subsets[x].parent = find(subsets[x].parent);
    }
    return subsets[x].parent;
}

void union_(int x, int y) 
{
    int xroot = find(x);
    int yroot = find(y);
    if (subsets[xroot].rank < subsets[yroot].rank) 
	{
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) 
	{
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int cmp(const void *a, const void *b) 
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal() 
{
    qsort(edges, num_edges, sizeof(Edge), cmp);
    for (int i = 0; i < num_vertices; i++) 
	{
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int mst_weight = 0, mst_size = 0;
    Edge mst[MAX_VERTICES - 1];
    for (int i = 0; i < num_edges && mst_size < num_vertices - 1; i++) 
	{
        Edge edge = edges[i];
        int u = edge.u, v = edge.v, weight = edge.weight;
        int uroot = find(u), vroot = find(v);
        if (uroot != vroot) 
		{
            mst[mst_size++] = edge;
            union_(uroot, vroot);
            mst_weight += weight;
        }
    }
    if (mst_size != num_vertices - 1) 
	{
        printf("No MST exists\n");
        return;
    }
    printf("MST weight: %d\n", mst_weight);
    printf("Edges in MST:\n");
    for (int i = 0; i < mst_size; i++) 
	{
        printf("(%d, %d, %d)\n", mst[i].u, mst[i].v, mst[i].weight);
    }
}
int main() 
{
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);
    printf("Enter the edges in the format 'u v weight':\n");
    for (int i = 0; i < num_edges; i++) 
	{
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    kruskal();
    return 0;
}

