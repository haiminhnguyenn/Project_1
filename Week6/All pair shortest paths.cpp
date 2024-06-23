#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 10001;
const int INF = INT_MAX;

int d[MAX_NODES][MAX_NODES];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

