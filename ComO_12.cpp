#include <bits/stdc++.h>

using namespace std;

int maxN = 0;

bool isSafe(int arr[8][8], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (arr[row][i] == -1)
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (arr[i][j] == -1)
            return false;
    }
    for (i = row, j = col; i < 8 && j >= 0; ++i, --j) {
        if (arr[i][j] == -1)
            return false;
    }
    return true;
}

bool hydra(int arr[8][8], int col, int value) {
    if (col >= 8) {
        if (value > maxN) {
            maxN = value;
        }
        return true;
    } else {
        for (int i = 0; i < 8; ++i) {
            if (isSafe(arr, i, col)) {
                int temp = arr[i][col];
                arr[i][col] = -1;
                if(hydra(arr, col + 1, value + temp)){
                    return true;
                }
                arr[i][col] = temp;
            }
        }
    }
    return false;
}

int main() {
    int T, map[8][8];
    cin >> T;
    for (int t = 0; t < T; ++t) {
        maxN = 0;
        for (auto &i : map) {
            for (int &j : i) {
                cin >> j;
            }
        }
        hydra(map, 0, 0);
        cout << maxN << "\n";
    }
}
