#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i + k < n) {
            dp[i] = max(dp[i + 1], a[i] + dp[i + k]);
        } else {
            dp[i] = max(dp[i + 1], a[i]);
        }
    }

    cout << dp[0] << endl;

    return 0;
}
