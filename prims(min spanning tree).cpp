#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

int minKey(vector<int>& key, vector<bool>& inMST) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void primMST(vector<vector<int>>& graph) {
    vector<int> parent(V);    // Stores MST structure
    vector<int> key(V, INT_MAX); // Used to pick minimum weight edge
    vector<bool> inMST(V, false); // Included in MST?

    key[0] = 0;     // Start from node 0
    parent[0] = -1; // First node is root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST); // Greedy choice
        inMST[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

int main() {
    // Adjacency matrix of graph
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
