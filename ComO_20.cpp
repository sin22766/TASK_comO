#include <bits/stdc++.h>
#define low -1000000
using namespace std;

int price[15000],n,dp[15000];

int rope(int l) {
    if(l<0){
        return low;
    }else if(l==0){
        return 0;
    }
    if(dp[l]!=0){
        return dp[l];
    }
    int maxi = low;
    for (int i = 0; i < n; ++i) {
        maxi = max(rope(l - i-1) + price[i], maxi);
    }
    return dp[l] = maxi;
}

int main() {
    int have;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    cin >> have;
    cout << rope(have);
    return 0;
}
