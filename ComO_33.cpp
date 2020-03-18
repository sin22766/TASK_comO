#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dp;

int emma4(int arr[],int l,int r){
    if(r-l==1){
        return max(arr[r],arr[l]);
    }else if(l==r){
        return arr[l];
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    return dp[l][r] = max(emma4(arr,l+2,r)+arr[l],emma4(arr,l+1,r-1)+arr[r]);
}

int emma9(int arr[],int l,int r){
    if(r-l==1){
        return max(arr[r],arr[l]);
    }else if(l==r){
        return arr[l];
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    return dp[l][r] = max(emma4(arr,l+2,r)+arr[l],emma4(arr,l+1,r-1)+arr[r]);
}

int emmaP(int arr[],int l,int r){
    if(r-l==1){
        return max(arr[r],arr[l]);
    }else if(l==r){
        return arr[l];
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    return dp[l][r] = max(emma4(arr,l+2,r)+arr[l],emma4(arr,l+1,r-1)+arr[r]);
}

int main() {
    int n;
    cin >> n;
    int arr[n],temp_arr[n];

    for (int i = 0;i < n;++i) {
        cin >> arr[i];
    }
    cout << emma4(arr,0,n-1);
    return 0;
}
