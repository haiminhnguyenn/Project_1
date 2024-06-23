#include <bits/stdc++.h>
using namespace std;

int findMax(int n, int arr[]) {
    int ans = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > ans) ans = arr[i];
    }
    return ans;
}

int findMin(int n, int arr[]) {
    int ans = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < ans) ans = arr[i];
    }
    return ans;
}

int sum(int n, int arr[]) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i];
    }
    return ans;
}

int findMaxSegment(int arr[],int begin, int end) {
    int ans = arr[begin - 1];
    for (int i = (begin - 1); i <= (end - 1); i++) {
        if (arr[i] > ans) ans = arr[i];
    }
    return ans;
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (true) {
        string query;
        cin >> query;
        if (query == "*") continue;
        else if (query == "***") break;
        else if (query == "find-max") cout << findMax(n, arr) << endl;
        else if (query == "find-min") cout << findMin(n, arr) <<endl;
        else if (query == "sum") cout << sum(n, arr) <<endl;
        else if (query == "find-max-segment") {
            int i, j;
            cin >> i >> j;
            cout << findMaxSegment(arr, i, j) << endl;
        }
    }
}
