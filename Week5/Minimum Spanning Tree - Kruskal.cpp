#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> parent;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end());

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;

    for (const Edge& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unionSets(edge.u, edge.v);
            mstWeight += edge.w;
        }
    }

    cout << mstWeight << endl;

    return 0;
}
