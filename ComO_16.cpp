#include<bits/stdc++.h>

using namespace std;

int chaos = 0;

void merge(int arr[], int left, int middle, int right, vector<int> &result) {
    int i = left, j = middle+1, k = left;
    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            result[k++] = arr[i++];
        } else {
            result[k++] = arr[j++];
            chaos += middle - i;
        }
    }
    while (i < middle) {
        result[k++] = arr[i++];
    }
    while (j <= right) {
        result[k++] = arr[j++];
    }
}

void mergeSort(int *arr, int low, int high) {
    if (low < high) {
        int mid = ((low + high) / 2);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        vector<int> result(high - low + 1);
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
        mergeSort(arr, 0, N - 1);
        for (auto j:arr) {
            cout << j << " ";
        }
        cout << "\n" << chaos << "\n";
    }
    return 0;
}

