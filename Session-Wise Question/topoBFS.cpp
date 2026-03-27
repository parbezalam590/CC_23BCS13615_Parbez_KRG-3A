#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V , vector<vector<int>>& adjList) {
    vector<int> inDegree(V, 0); // To store the in-degree of each vertex

    // Calculate the in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q; // Queue to store vertices with in-degree 0

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder; // To store the topological order

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node); // Add the current node to the topological order

        // Decrease the in-degree of neighboring vertices
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) { // If in-degree becomes 0, enqueue it
                q.push(neighbor);
            }
        }
    }

    return topoOrder; // Return the topological order
}

int main() {
    int V ,E ;
    cin >> V >> E;

    vector<vector<int>> adjList(V); // Adjacency list representation of the graph
    for(int i = 0; i < E ; i++) {
        int u , v ;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v to the adjacency list
    }
    vector<int> topoOrder = topoSort(V, adjList); // Get the topological order of the graph
    for(int vertex : topoOrder) {
        cout << vertex << " "; // Print the topological order
    }
    cout << endl;
    return 0;
    

}