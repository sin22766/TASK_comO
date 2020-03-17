#include <bits/stdc++.h>
using namespace std;

int song[1500], pause[1500], m, dp[1500];

int jd(int current) {
    if (current > m-1) {
        return 0;
    }
    if(dp[current]!= 0){
        return dp[current];
    }
    return dp[current] = max(jd(current+pause[current]+1)+song[current],jd(current+1));
}

int main() {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> song[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> pause[i];
    }
    cout << jd(0);
    return 0;
}
