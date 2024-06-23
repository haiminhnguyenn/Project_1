#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100001;
const int INF = INT_MAX;

vector<pair<int, int>> adj[MAX_NODES];
int dist[MAX_NODES];

void dijkstra(int start, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        if (u_dist != dist[u]) {
            continue;
        }

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s, n);

    if (dist[t] != INF) {
        cout << dist[t] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

