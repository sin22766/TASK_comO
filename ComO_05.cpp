#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool comparePlane(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> runway;
    vector<pair<int, int>> all;
    for (int i = 0; i < n; ++i) {
        pair<int, int> plane;
        plane.first = i;
        cin >> plane.second;
        all.push_back(plane);
        cin >> plane.second;
        all.push_back(plane);
    }
    sort(all.begin(), all.end(), comparePlane);
    for (pair<int, int> i:all) {
        if (runway.empty()) {
            runway.push(i);
        } else {
            if (runway.top().first == i.first) {
                runway.pop();
            } else {
                runway.push(i);
            }
        }
    }
    (runway.empty()) ? cout << "Yes" : cout << "No";
    return 0;
}