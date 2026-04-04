#include <bits/stdc++.h>
using namespace std;

int cheapestFlight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
    // adjacency list: node -> {neighbor, cost}
    vector<vector<pair<int,int>>> adj(n);
    for(auto &e : flights) {
        int u = e[0], v = e[1], cost = e[2];
        adj[u].push_back({v, cost});
    }

    // distance array
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // queue: {node, cost, stops}
    queue<tuple<int,int,int>> q;
    q.push({src, 0, 0});

    while(!q.empty()) {
        auto [node, cost, stops] = q.front();
        q.pop();

        // skip if stops exceed k
        if(stops > k) continue;

        for(auto &[nbr, wt] : adj[node]) {
            if(cost + wt < dist[nbr]) {
                dist[nbr] = cost + wt;
                q.push({nbr, dist[nbr], stops + 1});
            }
        }
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}
    };
    
    int src = 0, dst = 3, k = 1;

    int ans = cheapestFlight(n, flights, src, dst, k);

    cout << "Cheapest cost: " << ans << endl;

    return 0;
}