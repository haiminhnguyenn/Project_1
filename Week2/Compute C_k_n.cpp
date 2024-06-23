#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int k, n;
    cin >> k >> n;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || i == j) {
                dp[i][j] = 1;
            } else if (i > j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[k][n] << endl;

    return 0;
}
