#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool visited[MAX];
vector <int> graph[MAX];

void DFS(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) DFS(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS(i);
    }

    return 0;
}
