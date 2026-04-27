// Problem Statement: Given a connected, undirected graph with V vertices and E edges, find the Minimum Spanning Tree (MST) using Prim's algorithm. The graph is represented as an adjacency list, and the output should include the edges in the MST along with their weights, as well as the total weight of the MST.


#include <bits/stdc++.h>
using namespace std;

int main() {

    int V, E;
    cin >> V >> E;

    // Adjacency list
    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    // Min heap → {weight, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    // Start from node 0
    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;

        for(auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if(!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Print MST
    int totalWeight = 0;
    cout << "Edges in MST:\n";

    for(int i = 1; i < V; i++) {
        if(parent[i] == -1) {
            cout << "Graph is not connected\n";
            return 0;
        }
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }

    cout << "Total Weight = " << totalWeight << endl;

    return 0;
}

// Time complexity : O(E log V) where E is the number of edges and V is the number of vertices. This is because each edge is processed at most once, and each operation on the priority queue takes O(log V) time.
// Space complexity : O(V + E) for the adjacency list and O(V) for the key