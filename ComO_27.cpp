#include <bits/stdc++.h>

using namespace std;

vector<int> weight, price;

int chooseBU(int n, int w) {
    int dp[n][w];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i] > j) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][w - weight[i - 1]] + price[i - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n - 1][w - 1];
}

int main() {
    int CanW, Sum = 0, people, temp, n;
    cin >> n;
    price.assign(n, 0);
    weight.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> price[i] >> weight[i];
    }
    cin >> people;
    for (int j = 0; j < people; ++j) {
        cin >> temp;
        Sum += chooseBU(n, temp);
    }
    cout << Sum;
    return 0;
}

