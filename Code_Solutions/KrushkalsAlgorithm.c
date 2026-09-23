#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

// Bubble Sort
void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Find Parent
int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;

    return parent[component] = findParent(parent, parent[component]);

}

// Kruskal's Algorithm
void kruskal(struct Edge edges[], int V, int E) {
    int parent[V];
    int totalCost = 0;
    int count = 0;

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges
    sortEdges(edges, E);

    printf("Edges in MST:\n");

    for (int i = 0; i < E && count < V - 1; i++) {

       int u = findParent(parent, edges[i].src);    
        int v = findParent(parent, edges[i].dest);

        // If no cycle
        if (u != v) {
            parent[v] = u;

            totalCost += edges[i].weight;
            count++;
        }
    }

    printf("Total Cost = %d\n", totalCost);
}

int main() {
    struct Edge edges[] = {
        {0,1,4},
        {0,7,8},
        {1,2,8},
        {1,7,11},
        {2,3,7},
        {2,5,4},
        {2,8,2},
        {3,4,9},
        {3,5,14},
        {4,5,10},
        {5,6,2},
        {6,7,1},
        {6,8,6},
        {7,8,7}
    };

    int V = 9;
    int E = sizeof(edges) / sizeof(edges[0]);

    kruskal(edges, V, E);

    return 0;
}