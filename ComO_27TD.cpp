#include <bits/stdc++.h>

using namespace std;

vector<int> weight, price;
vector<vector<int>> dp;

int chooseTD(int n, int w) {
    if (w == 0 || n == 0) {
        return 0;
    }
    if(weight[n-1] > w){
        return chooseTD(n - 1, w);
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    return dp[n][w] = max(chooseTD(n - 1, w - weight[n-1]) + price[n-1], chooseTD(n - 1, w));
}

int main() {
    int CanW,Sum = 0,people,temp,n;
    cin >> n;
    vector<int> hx(n,-1);
    price.assign(n + 1, 0);
    weight.assign(n + 1, 0);
    dp.assign(n,hx);
    for (int i = 0; i < n; ++i) {
        cin >> price[i] >> weight[i];
    }
    cin >> people;
    cout << "Pass\n";
    for (int j = 0; j < people; ++j) {
        cin >> temp;
        Sum+=chooseTD(n, temp);
    }
    cout << Sum;
    return 0;
}
