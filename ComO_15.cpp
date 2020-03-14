#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

bool relax(vector<int> &dist, int &u, int &v, int &w) {
    if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        return true;
    }
    return false;
}

int main() {
    int nodeN, edgeN, u, v, w, count = 0;
    bool change;
    bool neg_cycle = false;
    Edge temp{};
    cin >> nodeN >> edgeN;
    vector<Edge> edgeList;
    vector<int> dist(nodeN, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < edgeN; ++i) {
        cin >> temp.u >> temp.v >> temp.w;
        edgeList.push_back(temp);
    }

    for (int j = 1; j < nodeN - 1; ++j) {
        change = false;
        for (auto edge : edgeList) {
            u = edge.u, v = edge.v, w = edge.w;
            change = relax(dist, u, v, w);
        }
        count++;
        if (count > nodeN - 1 && change) {
            neg_cycle = true;
            break;
        } else if (!change) {
            break;
        }
    }
    if (!neg_cycle) {
        for (auto i:dist) {
            cout << i << "\n";
        }
    }
    return 0;
}
