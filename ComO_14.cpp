#include <bits/stdc++.h>

using namespace std;

int d(vector<pair<int, int>> *g, int start, vector<bool> &visited, vector<int> dist) {
    priority_queue<pair<int, int>> q;
    q.push({dist[start], start});
}

int main() {
    int T, N, u, v;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        vector<pair<int,int>> g[N];
        for (int j = 0; j < N; ++j) {
            g[N]
        }
        cin >> u >> v;
        if (u != -1 && v != -1){
            g[u].emplace_back(v,0);
        }
    }

    return 0;
}
