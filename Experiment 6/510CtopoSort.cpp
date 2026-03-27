#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int indegree[26];

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        string s = names[i];
        string t = names[i + 1];

        int len = min(s.size(), t.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                adj[s[j] - 'a'].push_back(t[j] - 'a');
                indegree[t[j] - 'a']++;
                found = true;
                break;
            }
        }

        // Prefix check
        if (!found && s.size() > t.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // Topological Sort (Kahn's Algorithm)
    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string result = "";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result += (char)(node + 'a');

        for (auto nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    // If not all letters processed → cycle
    if (result.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}