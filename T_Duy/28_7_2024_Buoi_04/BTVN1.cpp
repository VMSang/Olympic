#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = a[1];

    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + a[i]);
    }

    cout << min(dp[n - 1], dp[n]) << endl;

    return 0;
}
