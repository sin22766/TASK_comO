#include <iostream>

using namespace std;

int sum = 0, bar;
bool possible = false;

void checkBar(int index, int arr[], int n) {
    if (index > n) {
        return;
    } else if (sum == bar && !possible) {
        cout << "YES\n";
        possible = true;
    } else {
        sum += arr[index];
        checkBar(index + 1, arr, n);
        sum -= arr[index];
        checkBar(index + 1, arr, n);
    }
}

int main() {
    int n;
    cin >> bar;
    cin >> n;
    int shortB[n];
    for (int i = 0; i < n; ++i) {
        cin >> shortB[i];
    }
    checkBar(0, shortB, n);
    if (!possible) {
        cout << "NO\n";
    }
    return 0;
}
