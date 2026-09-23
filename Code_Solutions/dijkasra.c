#include <stdio.h>
#include <stdbool.h>

#define INF 99999
#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int findMinDistance(int dist[], bool visited[]) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function implementing Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];      
    bool visited[V];  

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(dist, visited);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t\t ", i);
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    
   int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},  
        {7, 0, 10, 14, 0, 0},  
        {9, 10, 0, 11, 0, 2},  
        {0, 15, 11, 0, 6, 0} ,
        {0, 0, 0, 6, 0, 9} ,
        {14, 0, 2, 0, 9, 0}   
        
    };

    dijkstra(graph, 0); // Execute starting from source node 0

    return 0;
}