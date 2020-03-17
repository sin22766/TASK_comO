#include <bits/stdc++.h>

using namespace std;

vector<int> num;

bool choose(int sum, int i) {
    if (i == 0 && sum != 0) {
        return false;
    } else if (sum == 0) {
        return true;
    }
    return choose(sum - num[i - 1], i - 1) || choose(sum, i - 1);
}

bool chooseBU(int n, int sum) {
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i == 0 && j != 0) {
                dp[i][j] = false;
            } else if (i == 0) {
                dp[i][j] = true;
            } else {
                dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int n, sum = 0, temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        sum += temp;
        num.push_back(temp);
    }
    if (sum % 2 != 0) {
        cout << "NO";
    } else {
        (chooseBU(n,sum/2)) ? cout << "YES" : cout << "NO";
    }
    return 0;
}


