#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, w;
};

const int maxn = 1005;
int n, m; // đỉnh, cạnh
vector<edge> E; // tập cạnh
int parent[maxn], sz[maxn];

void nhap() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; 
        cin >> x >> y >> w;
        edge e{x, y, w};
        E.push_back(e);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nhap();
    init();
    sort(E.begin(), E.end(), [](edge a, edge b) {
        return a.w < b.w;
    });

    int mst_weight = 0;
    for (auto e : E) {
        if (Union(e.x, e.y)) {
            mst_weight += e.w;
        }
    }

    cout << mst_weight << "\n";

    return 0;
}
