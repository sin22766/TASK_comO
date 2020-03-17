#include <bits/stdc++.h>
using namespace std;

long dp[60];

long long kway(long k){
    if(k < 0)
        return 0;
    if(k == 0)
        return 1;
    if(dp[k]!=0){
        return dp[k];
    }
    return dp[k] = kway(k-1)+kway(k-3)+kway(k-4);
}

int main(){
    long long n;
    cin >> n;
    cout << kway(n);
    return 0;
}
