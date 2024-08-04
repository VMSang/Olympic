#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    vector<int> result;
    int index = 0;

    while (!v.empty()) {
        index = (index + 1) % v.size();
        result.push_back(v[index]);
        v.erase(v.begin() + index);
    }

    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }

    return 0;
}