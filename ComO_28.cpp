#include <bits/stdc++.h>

using namespace std;

int LCS(const string &a, const string &b) {
    int aL = a.length(), bL = b.length();
    int dp[aL + 1][bL + 1];
    for (int i = 0; i <= aL; ++i) {
        for (int j = 0; j <= bL; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[aL][bL];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << LCS(a, b);
    return 0;
}


