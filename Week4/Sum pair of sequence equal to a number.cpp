#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> count;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int complement = M - a[i];
        if (count.find(complement) != count.end()) {
            ans += count[complement];
        }
        count[a[i]]++;
    }

    cout << ans << endl;

    return 0;
}
