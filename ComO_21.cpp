#include <bits/stdc++.h>
#define inf 1e7
using namespace std;

int dp[10000];
int C[10000], n;

int minCoins(int m) {
    if (m < 0) {
        return inf;
    } else if (m == 0) {
        return 0;
    }
    if(dp[m]!=0){
        return dp[m];
    }
    int mini = inf;
    for (int i = 0; i < n; ++i) {
        int d = minCoins(m - C[i]);
        mini = min(d + 1, mini);
    }
    return dp[m] = mini;
}

int main() {
    int k;
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }
    cout << minCoins(k);
    return 0;
}