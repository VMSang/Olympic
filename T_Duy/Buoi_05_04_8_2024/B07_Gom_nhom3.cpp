#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210000;

vector<pair<int, int>> adj[MAXN];
vector<int> size(MAXN, 1);
vector<int> parent(MAXN);

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        for (const auto& p : adj[y]) {
            int neighbor = p.first;
            int dist = p.second;
            adj[x].push_back({neighbor, dist});
            adj[neighbor].push_back({x, dist});
        }
        adj[y].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) parent[i] = i;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        edges[i] = make_tuple(u, v, x);
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int u;
            cin >> u;
            cout << size[find(u)] << "\n";
        } else if (type == 3) {
            int u;
            cin >> u;
            int root = find(u);
            int min_dist = INT_MAX;
            for (const auto& p : adj[root]) {
                int v = p.first;
                int dist = p.second;
                int v_root = find(v);
                if (v_root != root) {
                    min_dist = min(min_dist, dist);
                }
            }
            cout << (min_dist == INT_MAX ? -1 : min_dist) << "\n";
        }
    }

    return 0;
}
