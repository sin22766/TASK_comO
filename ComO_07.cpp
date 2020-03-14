#include <bits/stdc++.h>

using namespace std;

bool comparePatient(pair<string, int> p1, pair<string, int> p2) {
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> group;
    stack<pair<string, int>> anti_dupe;
    for (int i = 0; i < n - 1; ++i) {
        pair<string, int> man;
        man.second = 0;
        cin >> man.first;
        group.push_back(man);
        man.second = 1;
        cin >> man.first;
        group.push_back(man);
    }
    sort(group.begin(), group.end(), comparePatient);
    for (auto i:group) {
        if (anti_dupe.empty()) {
            anti_dupe.push(i);
        } else {
            if (anti_dupe.top().first == i.first) {
                anti_dupe.pop();
            } else {
                anti_dupe.push(i);
            }
        }
    }
    if (anti_dupe.top().second == 1) {
        cout << anti_dupe.top().first;
    } else {
        anti_dupe.pop();
        cout << anti_dupe.top().first;
    }
    return 0;
}
