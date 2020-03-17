#include <bits/stdc++.h>

using namespace std;

//vector<int> dp;

int maxConBU(int n, int *arr) {
    int p[n + 1];
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            p[i] = -100000;
        } else {
            p[i] = max(arr[i - 1], p[i - 1] + arr[i - 1]);
        }
    }
    return p[n];
}

/*long long maxCon(long long *arr,long long i) {
    if(i <= 0)
        return 0;
    if(dp[i]!=INT_MIN){
        return dp[i];
    }
    return dp[i] = max(arr[i],arr[i]+maxCon(arr,i-1));
}*/

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << maxConBU(n, arr);
    return 0;
}
