#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<set<int>> &adj, int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

void ncycle_helper(vector<set<int>> &adj, vector<bool> &visited, int curr, int start, int &num_cycle, int n) {
    visited[curr] = true;
    if (n == 1) {
        if (adj[curr].count(start)) {
            num_cycle++;
        }
    } else {
        for (auto next:adj[curr]) {
            if (!visited[next])
                ncycle_helper(adj, visited, next, start, num_cycle, n - 1);
        }
    }
    visited[curr] = false;
}

int ncycle(vector<set<int>> &adj, int n) {
    vector<bool> visited(adj.size(), false);
    int num_cycle = 0;
    for (int v = 0; v < adj.size(); ++v) {
        ncycle_helper(adj, visited, v, v, num_cycle, n);
        visited[v] = true;
    }
    return num_cycle / 2;
}

int main() {
    int T;
    cin >> T;
    for (int j = 0; j < T; ++j) {
        int Vertex, Edge, n;
        cin >> Vertex >> Edge >> n;
        vector<set<int>> adj(Vertex);
        for (int i = 0; i < Edge; ++i) {
            int u, v;
            cin >> u >> v;
            addEdge(adj, u, v);
        }
        cout << ncycle(adj, n) << "\n";
    }
    return 0;
}
