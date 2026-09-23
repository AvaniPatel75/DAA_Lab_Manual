#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4

int minWeight(int weight[], bool visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && weight[i] < min)
        {
            min = weight[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void primMST(int graph[V][V])
{
    int weight[V];
    bool visited[V];

    int totalCost = 0;

    // Initialize arrays
    for (int i = 0; i < V; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    // Start from vertex 0
    weight[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = minWeight(weight, visited);

        visited[u] = true; 

        // Add minimum edge weight to total cost
        totalCost += weight[u];

        // Update weights of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < weight[v])
            {
                weight[v] = graph[u][v];
            }
        }
    }

    printf("Total Cost = %d\n", totalCost);
}

int main()
{
    int graph[V][V] = {
        {0, 3, 2, 0},
        {3, 0, 4, 1},
        {2, 4, 0, 5},
        {0, 1, 5, 0}
    };

    primMST(graph);

    return 0;
}