#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numList(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> numList[i];
    }
    for (int i = 0; i < n - 5; ++i) {
        for (int j = i + 1; j < n - 4; ++j) {
            for (int k = j + 1; k < n - 3; ++k) {
                for (int l = k + 1; l < n - 2; ++l) {
                    for (int m = l + 1; m < n - 1; ++m) {
                        for (int o = m + 1; o < n; ++o) {
                            cout << numList[i] << " " << numList[j] << " " << numList[k] << " " << numList[l] << " "
                                 << numList[m] << " " << numList[o] << "\n";
                        }
                    }
                }
            }
        }
    }
}
