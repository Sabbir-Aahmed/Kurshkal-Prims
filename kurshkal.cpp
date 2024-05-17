#include <iostream>
#include <algorithm>

using namespace std;

//structure to represent an edge
struct Edge {
    int src, dest, weight;
};

//function to find the set of an element i
int find(int parent[], int i) {
    if (parent[i] == -1) //if i is the root of the set
        return i;
    return find(parent, parent[i]); //recursively find the root of the set
}

void kruskal(Edge edges[], int V, int E) {
    Edge result[V - 1]; //array to store the result
    int parent[V]; //array to store the parent of each vertex for union find

    //initialize all vertices as their own pzrent
    for (int i = 0; i < V; ++i) {
        parent[i] = -1;
    }

    //sort all the edges in non-decreasing order of their weight
    sort(edges, edges + E, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int e = 0; //index to store the current edges in order

    //iterate through all sorted edges and construct the MST
    for (int i = 0; e < V - 1 && i < E; ++i) {
        Edge nextEdge = edges[i]; //get the next edges from the sorted list
        int x = find(parent, nextEdge.src); //find the root of the source vertex
        int y = find(parent, nextEdge.dest); //find the root of the destination vertex

        //if including this edge does not does not cause a cycle
        if (x != y) {
            result[e++] = nextEdge; //include the edge in the result

            // Merge two sets
            parent[y] = x;
        }
    }

    cout << "Edges of MST using Kruskal's algorithm:" << endl;
    for (int i = 0; i < V - 1; ++i) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}

int main() {
    int V = 9;  // Number of vertices
    int E = 14;  // Number of edges

    Edge edges[E];

    // Add edges
    edges[0] = {0, 1, 4};
    edges[1] = {0, 7, 8};
    edges[2] = {1, 7, 11};
    edges[3] = {1, 2, 8};
    edges[4] = {2, 3, 7};
    edges[5] = {2, 8, 2};
    edges[6] = {2, 5, 4};
    edges[7] = {7, 8, 7};
    edges[8] = {7, 6, 1};
    edges[9] = {8, 6, 6};
    edges[10] = {6, 5, 2};
    edges[11] = {3, 5, 14};
    edges[12] = {3, 4, 9};
    edges[13] = {5, 4, 10};

    kruskal(edges, V, E);

    return 0;
}
