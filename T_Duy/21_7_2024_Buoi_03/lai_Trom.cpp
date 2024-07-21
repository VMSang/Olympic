#include <bits/stdc++.h>
using namespace std;

long long calculateTotalValue(vector<int>& items, int x, int k) {
    int low_limit = x - k;
    int high_limit = x + k;

    auto low = lower_bound(items.begin(), items.end(), low_limit);
    auto high = upper_bound(items.begin(), items.end(), high_limit);

    long long total = 0;
    vector<int>::iterator it;

    for (it = items.begin(); it != low; ++it) {
        total += *it;
    }
    items.erase(items.begin(), low);

    high = upper_bound(items.begin(), items.end(), high_limit);

    for (it = high; it != items.end(); ++it) {
        total += *it;
    }
    items.erase(high, items.end());

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }

    sort(items.begin(), items.end());

    for (int i = 0; i < m; ++i) {
        int x, k;
        cin >> x >> k;
        cout << calculateTotalValue(items, x, k) << '\n';
    }

    return 0;
}
