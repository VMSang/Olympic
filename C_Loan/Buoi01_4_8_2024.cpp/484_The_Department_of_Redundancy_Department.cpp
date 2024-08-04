#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000001;
int a[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;
    int x;
    while (cin >> x) {
        if (a[x] == 0) {
            v.push_back(x);
            a[x] = 1;
        } else {
            a[x]++;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << a[v[i]] << "\n";
    }

    return 0;
}
