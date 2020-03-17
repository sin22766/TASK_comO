#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

long long maxConBU(long long *arr,long long i) {
    int j,k;
    int max_so_far = arr[0];
}

long long maxCon(long long *arr,long long i) {
    if(i <= 0)
        return 0;
    if(dp[i]!=INT_MIN){
        return dp[i];
    }
    return dp[i] = max(arr[i],arr[i]+maxCon(arr,i-1));
}

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    dp.assign(n,INT_MIN);
    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << maxCon(arr,n-1);
    return 0;
}
