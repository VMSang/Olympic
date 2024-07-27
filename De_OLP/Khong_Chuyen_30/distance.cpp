//tle
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<int> A(m), B(n);
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    sort(B.begin(), B.end());

    while (k--) {
        int L, R;
        cin >> L >> R;
        --L; --R;

        int min_distance = INT_MAX;
        for (int i = L; i <= R; ++i) {
            auto it = lower_bound(B.begin(), B.end(), A[i]);
            if (it != B.end()) {
                min_distance = min(min_distance, abs(A[i] - *it));
            }
            if (it != B.begin()) {
                min_distance = min(min_distance, abs(A[i] - *prev(it)));
            }
        }

        cout << min_distance << endl;
    }

    return 0;
}
