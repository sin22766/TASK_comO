#include <bits/stdc++.h>

using namespace std;

int Subtitle(const string &a, const string &b) {
    int aL = a.length(), bL = b.length();
    int dp[aL + 1][bL + 1];
    for (int i = 0; i <= aL; ++i) {
        for (int j = 0; j <= bL; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[aL][bL];
}

int main() {
    string a, b;
    cin >> a >> b;
    int g = Subtitle(a, b);
    int limit = ceil(max(a.length(), b.length()) / 2.0);
    bool gB = g < limit;
    cout << g << " " << gB;
    return 0;
}


