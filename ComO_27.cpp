#include <bits/stdc++.h>

using namespace std;

vector<int> weight, price;

int chooseBU(int n, int w) {
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j-weight[i]] + price[i], dp[i - 1][j]);
            }
        }
    }
    return dp[n][w];
}

int main() {
    int Sum = 0, people, temp, n;
    cin >> n;
    price.assign(n+1, 0);
    weight.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
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

