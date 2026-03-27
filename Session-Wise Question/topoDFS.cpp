// topological sort is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. One common algorithm to perform topological sort is Kahn's algorithm, which uses in-degrees of vertices.
// using DFS and stack to perform topological sort. The idea is to perform a depth-first search (DFS) on the graph and push each vertex onto a stack after visiting all its neighbors. Finally, we can pop all vertices from the stack to get the topological order.
#include<bits/stdc++.h>
using namespace std;


void dfs (int node , vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& st) {
    visited[node] = true; // Mark the current node as visited

    for (int neighbor : adjList[node]) { // Explore all neighbors of the current node
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, st); // Recursively perform DFS on unvisited neighbors
        }
    }
    st.push(node); // Push the current node onto the stack after visiting all its neighbors
} 

vector<int> topoSort(int V , vector<vector<int>>& adjList) {
    vector<bool> visited(V,false); // To keep track of visited vertices

    stack<int> st; // Stack to store the topological order

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, adjList, visited, st); // Perform DFS for unvisited vertices
        }
    }
    vector<int> result;
    while(!st.empty()) {
        result.push_back(st.top()); // Pop vertices from the stack to get the topological order
        st.pop();
    }

    return result; // Return the topological order
}

  

int main() {

   int V , E;
   cin >> V >> E;

   vector<vector<int>> adjList(V); // Adjacency list representation of the graph
   for (int i = 0; i< E ; i++) {
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


