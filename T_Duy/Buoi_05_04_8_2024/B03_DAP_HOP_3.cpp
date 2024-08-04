#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
int a[MAXN];
long long dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Khởi tạo dp và max_dp
    fill(dp, dp + n, 0);
    long long result = 0;

    // Duyệt mảng để tính giá trị tối đa
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i];
        for (int j = 0; j < i; ++j) {
            if (a[i] >= a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << "\n";
    return 0;
}
