#include<bits/stdc++.h>

using namespace std;
int chaos = 0;

void merge(int arr[], int left, int middle, int right, vector<int> &result) {
    int i = left, j = middle,k=left;
    while (i < middle && j <= right) {
        if (arr[i] <= arr[j]) {
            result.push_back(arr[i++]);
        } else {
            result.push_back(arr[j++]);
            chaos += middle-i;
        }
    }
    while (i < middle){
        result.push_back(arr[i++]);
    }
    while (j <= right){
        result.push_back(arr[j++]);
    }
}

void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        vector<int> result;
        result.clear();
        merge(arr, low, mid, high, result);
        copy(result.begin(), result.end(), arr + low);
    }
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        int arr[N];
        chaos = 0;
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }
        mergesort(arr, 0, N - 1);
        for (auto j:arr) {
            cout << arr[j] << " ";
        }
        cout << "\n";
        cout << chaos << "\n";
    }
    return 0;
}

