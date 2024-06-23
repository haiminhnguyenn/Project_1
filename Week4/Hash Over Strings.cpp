#include <bits/stdc++.h>
using namespace std;
#define MAX 200 + 5

int main() {
    int n, m, c[MAX];
    cin >> n >> m;

    c[0] = 1;
    for (int i = 1; i < MAX; i++) {
        c[i] = (c[i - 1] * 256) % m;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int hash = 0, k = s.size();
        for (int j = 0; j < k; j++) {
            int sj = (int) s[j];
            hash += sj * c[k - j - 1] % m;
            hash %= m;
        }

        cout << hash << "\n";
    }

    return 0;
}
