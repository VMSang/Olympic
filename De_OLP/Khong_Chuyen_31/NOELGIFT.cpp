#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100005;

vector<int> adj[MAX_N];
int deg[MAX_N] = {0};
bool visited[MAX_N] = {false};

int n, m, ans = 0;

void dfs(int u, int& totalDeg, int& numbVertex) {
    totalDeg += deg[u];
    ++numbVertex;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, totalDeg, numbVertex);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int totalDeg = 0, numbVertex = 0;
            dfs(i, totalDeg, numbVertex);
            ans += min(numbVertex, totalDeg / 2);
        }
    }

    cout << ans << endl;
    return 0;
}