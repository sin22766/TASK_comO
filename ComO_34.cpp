#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q,i1,j1,i2,j2;
    scanf("%d",&n);
    int land[n][n];
    long long prefix[n+1][n+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(i==0||j==0){
               prefix[i][j] = 0;
            }else{
                scanf("%d",&land[i-1][j-1]);
                prefix[i][j] = land[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
/*    for (long long k = 1; k <= n; ++k) {
        for (long long j = 1; j <= n; ++j) {
            cout << prefix[k][j] << " ";
        }
        cout << "\n";
    }*/
    scanf("%d",&q);
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d %d %d",&i1,&j1,&i2,&j2);
        i1++;j1++;i2++;j2++;
        cout << prefix[i2][j2] - prefix[i1-1][j2] - prefix[i2][j1-1] + prefix[i1-1][j1-1] << "\n";
    }
    return 0;
}
