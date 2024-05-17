#include <iostream>

using namespace std;

#define INF 9999999

int main() {
    int V=5;
    // Adjacency matrix to represent the graph
    int G[V][V] = {
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
    };

    bool selected[V]; // Array to keep track of selected vertices in the MST
    for (int i = 0; i < V; i++) {
        selected[i] = false; // Initialize all vertices as not selected
    }
    selected[0] = true; // Start from the first vertex
    int no_edge = 0; // Count of edges included in the MST

    cout << "Edge : Weight" << endl;

    //until we include V-1 edges in the MST
    while (no_edge < V - 1) {
        int minimum = INF; // Initialize minimum weight to a large value
        int x = 0, y = 0; // Variables to store the indices of the selected edge

        // Iterate over all vertices to find the minimum weight edge
        for (int i = 0; i < V; i++) {
            if (selected[i]) { // If vertex i is included in the MST
                for (int j = 0; j < V; j++) {
                    // If vertex j is not included and there is an edge between i and j
                    if (!selected[j] && G[i][j]) {
                        if (minimum > G[i][j]) { // Update minimum if a smaller weight is found
                            minimum = G[i][j]; // Update minimum weight
                            x = i; // Store the starting vertex of the edge
                            y = j; // Store the ending vertex of the edge
                        }
                    }
                }
            }
        }
        cout << x << "-" << y << " : " << G[x][y] << endl;
        selected[y] = true; // Mark the ending vertex as selected
        no_edge++; // Increment the count of edges included in the MST
    }

    return 0;
}
