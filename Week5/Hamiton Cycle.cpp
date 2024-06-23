/*
#include <bits/stdc++.h>
using namespace std;

bool isHamiltonian(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int pos, int n) {
    if (pos == n) {
        if (graph[path[n - 1]][path[0]])
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++) {
        if (!visited[v] && graph[path[pos - 1]][v]) {
            path[pos] = v;
            visited[v] = true;

            if (isHamiltonian(graph, path, visited, pos + 1, n))
                return true;

            path[pos] = -1;
            visited[v] = false;
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        vector<int> path(n, -1);
        vector<bool> visited(n, false);

        path[0] = 0;
        visited[0] = true;

        if (isHamiltonian(graph, path, visited, 1, n)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    int n = graph.size();
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

int isHamiltonian(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n, -1);

    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1))
        return 1;

    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        int result = isHamiltonian(graph);
        cout << result << endl;
    }

    return 0;
}

