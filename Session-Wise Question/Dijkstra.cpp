#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> graph[n+1];

    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    vector<long long> dist(n+1, 1e18);
    vector<int> parent(n+1);

    for(int i=1;i<=n;i++)
        parent[i] = i;

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        long long wt = it.first;
        int node = it.second;

        if(wt > dist[node]) continue;

        for(auto adjNode : graph[node]) {

            int v = adjNode.first;
            int weight = adjNode.second;

            if(dist[node] + weight < dist[v]) {

                dist[v] = dist[node] + weight;
                parent[v] = node;

                pq.push({dist[v], v});
            }
        }
    }

    if(dist[n] == 1e18) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    int node = n;

    while(parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    for(int x : path)
        cout << x << " ";
}