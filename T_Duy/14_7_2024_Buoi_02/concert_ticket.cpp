#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s.insert(x);
    }

    while (m--) {
        int x; cin >> x;
        auto it = s.upper_bound(x);

        if (it != s.begin()) {
            --it;
            cout << *it << "\n";
            s.erase(it);
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
