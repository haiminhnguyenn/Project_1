#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, M;
vector<vector<int>> graph;
vector<vector<int>> capacity;
vector<vector<int>> flow;

int fordFulkerson(int source, int target) {
    int maxFlow = 0;
    while (true) {
        vector<int> parent(N, -1);
        queue<int> q;
        q.push(source);
        while (!q.empty() && parent[target] == -1) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < N; v++) {
                if (parent[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                }
            }
        }
        if (parent[target] == -1) {
            break;
        }
        int pathFlow = INF;
        for (int v = target; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
        }
        for (int v = target; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    cin >> N >> M;
    graph.assign(N, vector<int>());
    capacity.assign(N, vector<int>(N, 0));
    flow.assign(N, vector<int>(N, 0));

    int s, t;
    cin >> s >> t;

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        capacity[u - 1][v - 1] = c;
    }

    int maxFlow = fordFulkerson(s - 1, t - 1);
    cout << maxFlow << endl;

    return 0;
}
