#include <bits/stdc++.h>

const long long moder = (1e9) + 7;

using namespace std;

vector<long long> dp_guard;
vector<long long> dp_pow4;

long long guard(int day) {
    int guard_size = dp_guard.size();
    for (int i = guard_size; i <= day; ++i) {
        dp_pow4.push_back(0);
        dp_pow4[i] = (dp_pow4[i - 1] * 4)%moder;
        dp_guard.push_back(0);
        dp_guard[i] = (dp_pow4[i - 1] % moder + (2%moder * dp_guard[i - 1]%moder) % moder) % moder;
    }
    return dp_guard[day];
}

int main() {
    int T, temp;
    cin >> T;
    dp_pow4 = {0, 4};
    dp_guard = {0, 1};
    for (int i = 0; i < T; ++i) {
        cin >> temp;
        cout << guard(temp) << "\n";
    }
    return 0;
}
