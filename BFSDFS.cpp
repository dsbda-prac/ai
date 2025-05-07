#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// --------- Undirected Graph Representation ---------

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // because it's undirected
}

// --------- Recursive Depth First Search (DFS) ---------

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            DFS(neighbor, graph, visited); // Recursive call
    }
}

// --------- Breadth First Search (BFS) ---------

void BFS(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// --------- Main Function ---------

int main() {
    int V = 6; // Number of vertices (0 to 5)
    vector<vector<int>> graph(V);

    // Define edges (example graph)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    cout << "DFS traversal (recursive): ";
    vector<bool> visitedDFS(V, false);
    DFS(0, graph, visitedDFS); // Start DFS from node 0
    cout << endl;

    cout << "BFS traversal (iterative): ";
    vector<bool> visitedBFS(V, false);
    BFS(0, graph, visitedBFS); // Start BFS from node 0
    cout << endl;

    return 0;
}
