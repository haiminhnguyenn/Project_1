#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    map<int, int> lastIndex;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        if (lastIndex.find(A[i]) != lastIndex.end()) {
            result[i] = 1;
        }
        lastIndex[A[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
